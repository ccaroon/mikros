#include "MultiFunction.h"
#include <Arduino.h>

void MultiFunction::begin() {
    CircuitPlayground.begin();
    CircuitPlayground.clearPixels();
    CircuitPlayground.redLED(false);
}

void MultiFunction::loop() {

    if (CircuitPlayground.slideSwitch()) {
        CircuitPlayground.clearPixels();
    } else {

        if (CircuitPlayground.rightButton()) {
            currentFunction += 1;
            if (currentFunction > NUM_ACTIONS) {
                currentFunction = 1;
            }
        }

        switch (currentFunction) {
        case ACTION_COLORLOOP:
            colorLoop();
            // CircuitPlayground.colorWheel(1);
            break;
        case ACTION_TILT:
            tilt();
            break;
        case ACTION_DISPLAYTEMP:
            displayTemp();
            break;
        case ACTION_DISPLAYILLUM:
            displayIllumination();
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
    if (millis() - lastUpdated > UPDATE_INTERVAL) {
        float tempF = CircuitPlayground.temperatureF();

        uint8_t num_pixels = map(tempF, 0, 100, 0, 10);

        for (uint8_t i = 0; i < num_pixels; i++) {
            if (i < 7) {
                CircuitPlayground.setPixelColor(i, 0, (i * 42.5),
                                                255 - (i * 42.5));
            } else if (i >= 7) {
                CircuitPlayground.setPixelColor(i, ((i - 6) * 85),
                                                255 - ((i - 6) * 42.5), 0);
            }
        }

        // Turn off the rest of the pixels
        for (uint8_t i = num_pixels; i < 10; i++) {
            CircuitPlayground.setPixelColor(i, 0x000000);
        }

        lastUpdated = millis();
    }
}

// void MultiFunction::displayTemp() {
//
//     if (millis() - lastUpdated > UPDATE_INTERVAL) {
//         float tempF = CircuitPlayground.temperatureF();
//         Serial.println(tempF);
//
//         uint8_t p = map(tempF, 0, 100, 0, 10);
//
//         for (uint8_t i = 0; i < p; i++) {
//             CircuitPlayground.setPixelColor(i, TempColorMap[i]);
//         }
//
//         // Turn off the rest of the pixels
//         for (uint8_t i = p; i < 10; i++) {
//             CircuitPlayground.setPixelColor(i, 0x000000);
//         }
//
//         lastUpdated = millis();
//     }
// }

void MultiFunction::displayIllumination() {

    if (millis() - lastUpdated > UPDATE_INTERVAL) {
        uint16_t light1 = CircuitPlayground.lightSensor();
        delay(100);
        uint16_t light2 = CircuitPlayground.lightSensor();
        uint16_t light = light1 > light2 ? light1 : light2;

        // Map light to a number between 0 and 10*255 (10 NeoPixels, 255
        // Brightness)
        uint16_t adjLight = map(light, 0, 1023, 0, 2549);

        Serial.print(light);
        Serial.print(" <--> ");
        Serial.println(adjLight);
        // CircuitPlayground.clearPixels();

        // Set full-on pixels
        uint8_t pixelIndex = 0;
        while (adjLight > 255) {
            CircuitPlayground.setPixelColor(pixelIndex, 255, 255, 255);

            adjLight -= 255;
            pixelIndex += 1;
        }

        // Set last pixel to remainder l
        CircuitPlayground.setPixelColor(pixelIndex++, adjLight, adjLight,
                                        adjLight);

        // Turn off the rest of the pixels
        for (uint8_t i = pixelIndex; i < 10; i++) {
            CircuitPlayground.setPixelColor(i, 0x000000);
        }

        lastUpdated = millis();
    }
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

    Serial.println("----------------------------------------");
    Serial.print("x: ");
    Serial.println(x);
    Serial.print("y: ");
    Serial.println(y);
    Serial.print("z: ");
    Serial.println(z);

    delay(100);
}
