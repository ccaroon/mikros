//------------------------------------------------------------------------------
//  TinyCircuits Compass TinyShield Library
//  Using Honeywell HMC5883 in I2C mode
//
// With code borrowed from:
// * Ken Burns: http://www.hackster.io/kburns/getting-started-tinyshield-compass
// * Tony Batey: http://www.hackster.io/tbatey_tiny-circuits/tinycompass
//------------------------------------------------------------------------------
#include <math.h>
#include <Wire.h>
#include "TinyCompass.h"

TinyCompass::TinyCompass() {
}

void TinyCompass::init() {
    //Put the HMC5883 into operating mode
    Wire.beginTransmission(HMC5883_I2CADDR);
    Wire.write(0x02);     // Mode register
    Wire.write(0x00);     // Continuous measurement mode
    Wire.endTransmission();  
}

void TinyCompass::read() {
    uint8_t ReadBuff[6];

    // Read the 6 data bytes from the HMC5883
    Wire.beginTransmission(HMC5883_I2CADDR);
    Wire.write(0x03);
    Wire.endTransmission();
    Wire.requestFrom(HMC5883_I2CADDR,6);

    for(int i = 0; i < 6;i++) {
       ReadBuff[i] = Wire.read();
    }

    this->x = ReadBuff[0] << 8;
    this->x |= ReadBuff[1];

    this->y = ReadBuff[4] << 8;
    this->y |= ReadBuff[5];

    this->z = ReadBuff[2] << 8;
    this->z |= ReadBuff[3];

    // Find values of hard iron distortion
    // This will store the max and min values of the magnetic field around you    
    if(this->x > this->x_max) {
        this->x_max = this->x;
    }

    if(this->y > this->y_max) {
        this->y_max = this->y;
    }
        
    if(this->y < this->y_min) {
        this->y_min = this->y;
    }
        
    if(this->x < this->x_min) {
        this->x_min = this->x;
    }

    int xoffset = (this->x_max + this->x_min) / 2;
    int yoffset = (this->y_max + this->y_min) / 2;

    int x_scale = this->x - xoffset; // Math to compensate for hard
    int y_scale = this->y - yoffset; // iron distortions

    // Heading in radians
    float heading = atan2(x_scale, y_scale); 

    //Heading between 0 and 6.3 radians
    if(heading < 0) {
        heading += 2 * M_PI;
    }

    if(heading > 2*M_PI) {
        heading -= 2 * M_PI;
    }

    //Conversion to degrees  
    this->degrees = heading * 180/M_PI;
}

int TinyCompass::getX() {
    return this->x;
}

int TinyCompass::getY() {
    return this->y;
}

int TinyCompass::getZ() {
    return this->z;
}

int TinyCompass::getDegrees() {
    return this->degrees;
}
