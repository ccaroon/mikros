#include "Effects.h"
#include "NeoCandle.h"

Effects::Effects() {
    this->strip =
        Adafruit_NeoPixel(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
    this->strip.begin();

    this->neoCandle = new NeoCandle(&strip);
}

void Effects::off() {
    this->strip.clear();
    this->strip.show();
}

void Effects::candle() {
    this->neoCandle->loop();
}

void Effects::lamp(uint8_t r, uint8_t g, uint8_t b) {
    for (unsigned int i = 0; i < this->strip.numPixels(); i++) {
        this->strip.setPixelColor(i, r, g, b);
    }
    this->strip.show();
}

void Effects::blinkOnBoardLED(uint8_t r, uint8_t g, uint8_t b) {
    Bean.setLed(random(r), random(g), random(b));
}

Effects::~Effects() {
    delete this->neoCandle;
}
