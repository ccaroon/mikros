#include "Charliplexing.h"
#include "TinyCompass.h"

#define N  0
#define NE 45
#define E  90
#define SE 135
#define S  180
#define SW 225
#define W  270
#define NW 315

TinyCompass compass = TinyCompass();

void setup() {
    LedSign::Init();
    compass.init();
}

void loop() {
    int degrees;

    compass.read();

    degrees = compass.getDegrees();
    LedSign::Clear(0);
    if (degrees >= N and degrees < NE) {
        LedSign::Set(2,0,1);
        LedSign::Set(3,0,1);
    }
    else if (degrees >= NE && degrees <= E) {
        LedSign::Set(5,3,1);
        LedSign::Set(5,4,1);
        LedSign::Set(5,5,1);
    }
    else if (degrees > E && degrees < SE) {
        LedSign::Set(5,3,1);
        LedSign::Set(5,4,1);
        LedSign::Set(5,5,1);
    }
    else if (degrees >= SE && degrees <= S) {
        LedSign::Set(2,8,1);
        LedSign::Set(3,8,1);
    }
    else if (degrees > S && degrees < SW) {
        LedSign::Set(2,8,1);
        LedSign::Set(3,8,1);
    }
    else if (degrees >= SW && degrees <= W) {
        LedSign::Set(0,3,1);
        LedSign::Set(0,4,1);
        LedSign::Set(0,5,1);
    }
    else if (degrees > W && degrees < NW) {
        LedSign::Set(0,3,1);
        LedSign::Set(0,4,1);
        LedSign::Set(0,5,1);
    }
    else if (degrees >= NW && degrees < 360) {
        LedSign::Set(2,0,1);
        LedSign::Set(3,0,1);
    }
    
    delay(250);
}




