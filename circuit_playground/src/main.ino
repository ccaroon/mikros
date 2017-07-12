#include <stdio.h>

#include <Adafruit_CircuitPlayground.h>
#define TILT_COLOR 0x00FF77

void setAllColor(uint32_t color) {
    for (uint8_t i = 0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, color);
    }
}

void setup() {
    Serial.begin(9600);
    CircuitPlayground.begin();
    CircuitPlayground.clearPixels();

    setAllColor(TILT_COLOR);
}

void colorLoop() {
    uint8_t r, g, b;

    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);

    for (uint8_t i = 0; i < 10; i++) {
        CircuitPlayground.setPixelColor(i, r, g, b);
        delay(250);
    }
}

void displayTemp() {
    float tempF = CircuitPlayground.temperatureF();

    Serial.println(tempF);

    if (tempF >= 90.0) {
        CircuitPlayground.setPixelColor(2, 255, 0, 0);
    } else {
        CircuitPlayground.setPixelColor(2, 0, 255, 0);
    }

    delay(1000);
}

void tilt() {

    float x = CircuitPlayground.motionX();
    float y = CircuitPlayground.motionY();
    float z = CircuitPlayground.motionZ();

    if (x > -5 && x < 5 && y > -5 && y < 5) {
        setAllColor(TILT_COLOR);
    } else if (x <= -5) {
        CircuitPlayground.clearPixels();
        CircuitPlayground.setPixelColor(0, TILT_COLOR);
        CircuitPlayground.setPixelColor(1, TILT_COLOR);
        CircuitPlayground.setPixelColor(8, TILT_COLOR);
        CircuitPlayground.setPixelColor(9, TILT_COLOR);
    } else if (x >= 5) {
        CircuitPlayground.clearPixels();
        CircuitPlayground.setPixelColor(3, TILT_COLOR);
        CircuitPlayground.setPixelColor(4, TILT_COLOR);
        CircuitPlayground.setPixelColor(5, TILT_COLOR);
        CircuitPlayground.setPixelColor(6, TILT_COLOR);
    } else if (y <= -5) {
        CircuitPlayground.clearPixels();
        CircuitPlayground.setPixelColor(0, TILT_COLOR);
        CircuitPlayground.setPixelColor(1, TILT_COLOR);
        CircuitPlayground.setPixelColor(2, TILT_COLOR);
        CircuitPlayground.setPixelColor(3, TILT_COLOR);
        CircuitPlayground.setPixelColor(4, TILT_COLOR);
    } else if (y >= 5) {
        CircuitPlayground.clearPixels();
        CircuitPlayground.setPixelColor(5, TILT_COLOR);
        CircuitPlayground.setPixelColor(6, TILT_COLOR);
        CircuitPlayground.setPixelColor(7, TILT_COLOR);
        CircuitPlayground.setPixelColor(8, TILT_COLOR);
        CircuitPlayground.setPixelColor(9, TILT_COLOR);
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

void loop() {
    // colorLoop();
    // displayTemp();
    tilt();
}
