#ifndef __EFFECTS_H__
#define __EFFECTS_H__

#include "NeoCandle.h"
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_COUNT 10
#define NEOPIXEL_PIN 4

class Effects {
public:
    Effects();
    ~Effects();

    void candle();
    void lamp(uint8_t r, uint8_t g, uint8_t b);
    // void breath();
    // void slowCycle();
    // void fastCycle();
    void off();
    void blinkOnBoardLED(uint8_t,uint8_t,uint8_t);

private:
    Adafruit_NeoPixel strip;
    NeoCandle *neoCandle;
};

#endif
