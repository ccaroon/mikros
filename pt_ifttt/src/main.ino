#include "neopixel.h"

#define PIXEL_PIN D0
#define PIXEL_COUNT 1
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int setRandomColor(String color) {
    uint8_t r, g, b;

    if (color == "green") {
        r = 0;
        g = random(0, 255);
        b = 0;
    } else {
        r = random(0, 255);
        g = random(0, 255);
        b = random(0, 255);
    }

    strip.setPixelColor(0, r, g, b);
    strip.show();

    return 0;
}

void setup() {
    Particle.function("randColor", setRandomColor);

    strip.begin();

    randomSeed(analogRead(0));
    setRandomColor("");
}

void loop() {
    // setRandomColor();
    // delay(3000);
    // strip.setPixelColor(0, 0, 255, 0);
    // strip.show();
    // delay(1000);
    //
    // strip.setPixelColor(0, 255, 0, 0);
    // strip.show();
    // delay(1000);
}
