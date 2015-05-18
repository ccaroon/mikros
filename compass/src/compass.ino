#include "Charliplexing.h"
#include "TinyCompass.h"

#include "indicators.h"

TinyCompass compass = TinyCompass();


void selfTest() {
    LedSign::Clear(1);
    delay(1000);
    LedSign::Clear(0);
    delay(1000);

    for (int i = 0; i < 360; i+=45) {
        indicateSimpleDirection(i);
        delay(250);
    }
}

void setup() {
    LedSign::Init();
    compass.init();

    selfTest();
}

void loop() {
    int degrees;

    compass.read();

    degrees = compass.getDegrees();

    LedSign::Clear(0);

    // uint8_t led = degrees / 20;
    // ledOn(led);

    if (degrees >= CP_1 && degrees <= CP_2) {
        indicateSimpleDirection(CP_1);
    }
    else if (degrees > CP_2 && degrees <= CP_3) {
        indicateSimpleDirection(CP_3);
    }
    else if (degrees > CP_3 && degrees <= CP_4) {
        indicateSimpleDirection(CP_3);
    }
    else if (degrees > CP_4 && degrees <= CP_5) {
        indicateSimpleDirection(CP_5);
    }
    else if (degrees > CP_5 && degrees <= CP_6) {
        indicateSimpleDirection(CP_5);
    }
    else if (degrees > CP_6 && degrees <= CP_7) {
        indicateSimpleDirection(CP_7);
    }
    else if (degrees > CP_7 && degrees <= CP_8) {
        indicateSimpleDirection(CP_7);
    }
    else if (degrees > CP_8 && degrees <= CP_9) {
        indicateSimpleDirection(CP_9);
    }
    else if (degrees > CP_9 && degrees <= CP_10) {
        indicateSimpleDirection(CP_9);
    }
    else if (degrees > CP_10 && degrees <= CP_11) {
        indicateSimpleDirection(CP_11);
    }
    else if (degrees > CP_11 && degrees <= CP_12) {
        indicateSimpleDirection(CP_11);
    }
    else if (degrees > CP_12 && degrees <= CP_13) {
        indicateSimpleDirection(CP_13);
    }
    else if (degrees > CP_13 && degrees <= CP_14) {
        indicateSimpleDirection(CP_13);
    }
    else if (degrees > CP_14 && degrees <= CP_15) {
        indicateSimpleDirection(CP_15);
    }
    else if (degrees > CP_15 && degrees <= CP_16) {
        indicateSimpleDirection(CP_15);
    }
    else if (degrees > CP_16) {
        indicateSimpleDirection(CP_1);
    }
    
    delay(250);
}
