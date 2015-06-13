#include "TinyJoystick.h"
#include <Wire.h>

TinyJoystick::TinyJoystick() {
    this->LB = false;
    this->RB = false;
    // this.RX = 0;
    // this.RY = 0;
    // this.LX = 0;
    // this.RX = 0;
}

void TinyJoystick::read() {
    Wire.requestFrom(0x22, 6);
    
    int data[4];
    for(int i = 0; i < 4; i++){
        data[i] = Wire.read();
    }

    uint8_t lsb     = Wire.read();
    uint8_t buttons = ~Wire.read();
    this->LB = buttons&4 ? true : false;
    this->RB = buttons&8 ? true : false;

    for(int i = 0; i < 4; i++) {
        data[i] <<= 2;
        data[i] |= ((lsb>>(i*2))&3);
        data[i] -= 511;
    }

    this->rightStick.x = data[0];
    this->rightStick.y = -data[1];
    this->leftStick.x  = -data[2];
    this->leftStick.y  = data[3];
}

bool TinyJoystick::leftButtonPressed() {
    return (this->LB);
}

bool TinyJoystick::rightButtonPressed() {
    return (this->RB);
}

Location TinyJoystick::getLeftStick() {
    return (this->leftStick);
}

Location TinyJoystick::getRightStick() {
    return (this->rightStick);
}
