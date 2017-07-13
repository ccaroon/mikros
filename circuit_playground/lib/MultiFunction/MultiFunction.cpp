#include "MultiFunction.h"
#include <Arduino.h>

void MultiFunction::begin() {
    CircuitPlayground.begin();
    CircuitPlayground.clearPixels();
    CircuitPlayground.redLED(false);
}

void MultiFunction::loop() {

    if (!CircuitPlayground.slideSwitch()) {
        CircuitPlayground.clearPixels();
        // LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
    } else {

        if (CircuitPlayground.rightButton()) {
            currentFunction += 1;
            if (currentFunction > 2) {
                currentFunction = 0;
            }
        }

        switch (currentFunction) {
        case ACTION_COLORLOOP:
            colorLoop();
            break;
        case ACTION_TILT:
            tilt();
            break;
        case ACTION_DISPLAYTEMP:
            displayTemp();
            break;
        }
    }
}

void MultiFunction::setAllColor(uint32_t color) {
    for (uint8_t i = 0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, color);
    }
}

void MultiFunction::colorLoop() {
    uint8_t r, g, b;

    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);

    for (uint8_t i = 0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, r, g, b);
        delay(250);
    }
}

void MultiFunction::displayTemp() {
    float tempF = CircuitPlayground.temperatureF();

    Serial.println(tempF);

    if (tempF >= 90.0) {
        CircuitPlayground.setPixelColor(2, 255, 0, 0);
    } else {
        CircuitPlayground.setPixelColor(2, 0, 255, 0);
    }

    delay(1000);
}

void MultiFunction::tilt() {

    float x = CircuitPlayground.motionX();
    float y = CircuitPlayground.motionY();
    float z = CircuitPlayground.motionZ();

    if (x <= -1.0 && y <= -1.0) {
        // setAllColor(TILT_COLOR);
        if (y < 0.00 && y > -3.33) {
            CircuitPlayground.clearPixels();
            CircuitPlayground.setPixelColor(0, TILT_COLOR);
            Serial.println("Quad 0");
        } else if (y <= -3.33 && y > -6.66) {
            CircuitPlayground.clearPixels();
            CircuitPlayground.setPixelColor(1, TILT_COLOR);
            Serial.println("Quad 1");
        } else {
            Serial.println("Unknown Quad");
        }
    } else {
        CircuitPlayground.clearPixels();
    }

    // led 2 & 7 should be a special case?
    if (x < 1.0 && x > -1.0 && y <= -6.66) {
        CircuitPlayground.clearPixels();
        CircuitPlayground.setPixelColor(2, TILT_COLOR);
        Serial.println("Quad 3");
    }

    // if (x > -5 && x < 5 && y > -5 && y < 5) {
    //     setAllColor(TILT_COLOR);
    // } else if (x <= -5) {
    //     CircuitPlayground.clearPixels();
    //     CircuitPlayground.setPixelColor(0, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(1, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(8, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(9, TILT_COLOR);
    // } else if (x >= 5) {
    //     CircuitPlayground.clearPixels();
    //     CircuitPlayground.setPixelColor(3, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(4, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(5, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(6, TILT_COLOR);
    // } else if (y <= -5) {
    //     CircuitPlayground.clearPixels();
    //     CircuitPlayground.setPixelColor(0, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(1, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(2, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(3, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(4, TILT_COLOR);
    // } else if (y >= 5) {
    //     CircuitPlayground.clearPixels();
    //     CircuitPlayground.setPixelColor(5, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(6, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(7, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(8, TILT_COLOR);
    //     CircuitPlayground.setPixelColor(9, TILT_COLOR);
    // }

    Serial.println("----------------------------------------");
    Serial.print("x: ");
    Serial.println(x);
    Serial.print("y: ");
    Serial.println(y);
    Serial.print("z: ");
    Serial.println(z);

    delay(100);
}
