#ifndef __EFFECTS_H__
#define __EFFECTS_H__

#include "NeoCandle.h"
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_COUNT 15
#define NEOPIXEL_PIN 7

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

  private:
    Adafruit_NeoPixel strip;
    NeoCandle *neoCandle;
};

#endif
