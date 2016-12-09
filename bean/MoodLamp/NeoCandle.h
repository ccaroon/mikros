// candle for Adafruit NeoPixel
// 8 pixel version
// by Tim Bartlett, December 2013
//
// Converted to a class by Craig N. Caroon, Sept 2016
#ifndef __NEOCANDLE_H__
#define __NEOCANDLE_H__

#include <Adafruit_NeoPixel.h>

class NeoCandle {
public:
    // NeoCandle(){};
    NeoCandle(Adafruit_NeoPixel *);

    void loop();

    void fire(int grnLow);
    void on(int f);
    void burn(int f);
    void flicker(int f);
    void flutter(int f);

private:
    Adafruit_NeoPixel *strip;

    // pay no attention to that man behind the curtain
    int fDelay;
    int fRep;

    // color variables: mix RGB (0-255) for desired yellow
    const uint8_t redPx = 255;
    const uint8_t grnHigh = 100;
    const uint8_t bluePx = 10;

    // animation time variables, with recommendations
    const uint8_t burnDepth =
        6; // how much green dips below grnHigh for normal burn
    const uint8_t flutterDepth = 20; // maximum dip for flutter
    const uint8_t cycleTime = 120;   // duration of one dip in milliseconds

    const int flickerDepth = (burnDepth + flutterDepth) / 2.4;
    const int burnDelay = (cycleTime / 2) / burnDepth;
    const int burnLow = grnHigh - burnDepth;
    const int flickDelay = (cycleTime / 2) / flickerDepth;
    const int flickLow = grnHigh - flickerDepth;
    const int flutDelay = ((cycleTime / 2) / flutterDepth);
    const int flutLow = grnHigh - flutterDepth;
};

#endif
