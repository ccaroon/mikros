#include "neopixel.h"

#define PIXEL_PIN D0
#define PIXEL_COUNT 150
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int remoteControl(String cmd) {
    uint8_t r, g, b;

    if (cmd == "deploy") {
        r = 0;
        g = random(0, 255);
        b = 0;
    } else if (cmd == "spinner") {
        r = random(0, 255);
        g = 0;
        b = 0;
    } else if (cmd == "test") {
        r = 0;
        g = 0;
        b = random(0, 255);
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
    // Particle.function("remoteCntl", remoteControl);

    strip.begin();

    randomSeed(Time.now());
    // remoteControl("");
}

#define COUNT 10
int last[COUNT] = {0};
void twinkle() {
    int r, g, b;

    for (int i = 0; i < COUNT; i++) {
        strip.setPixelColor(last[i], 0, 0, 0);
        last[i] = random(0, 150);

        r = random(25, 255);
        g = random(25, 255);
        b = random(25, 255);
        strip.setPixelColor(last[i], r, g, b);
    }

    strip.show();

    delay(150);
}

void walk() {
    int r, g, b;

    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);
    for (int i = 0; i < 150; i++) {
        strip.setPixelColor(i, r, g, b);
        strip.show();
        delay(100);
    }

    delay(750);
}

void loop() {
    walk();
    // twinkle();
}
