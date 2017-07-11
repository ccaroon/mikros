#include <Adafruit_CircuitPlayground.h>

void setup() {
    CircuitPlayground.begin();
    CircuitPlayground.clearPixels();
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

void loop() {
    // colorLoop();
}
