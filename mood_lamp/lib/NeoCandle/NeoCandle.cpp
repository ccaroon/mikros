// candle for Adafruit NeoPixel
// 8 pixel version
// by Tim Bartlett, December 2013
//
// Converted to a class by Craig N. Caroon, Sept 2016
#include "NeoCandle.h"
#include <Adafruit_NeoPixel.h>

NeoCandle::NeoCandle(Adafruit_NeoPixel *s) { this->strip = s; }

// In loop, call CANDLE STATES, with duration in seconds
// 1. on() = solid yellow
// 2. burn() = candle is burning normally, flickering slightly
// 3. flicker() = candle flickers noticably
// 4. flutter() = the candle needs air!
void NeoCandle::loop() {
  this->strip->setPixelColor(0, 255, 0, 255);
  this->strip->show();
  // burn(10);
  // flicker(5);
  // burn(8);
  // flutter(6);
  // burn(3);
  // on(10);
  // burn(10);
  // flicker(10);
}

// basic fire funciton - not called in main loop
void NeoCandle::fire(int grnLow) {
  for (int grnPx = grnHigh; grnPx > grnLow; grnPx--) {
    int halfGrn = grnHigh - ((grnHigh - grnPx) / 2);
    int darkGrn = grnPx - 70;
    darkGrn = constrain(darkGrn, 5, 255);
    strip->setPixelColor(0, redPx - 180, darkGrn, 0);
    strip->setPixelColor(1, redPx - 180, darkGrn, 0);
    strip->setPixelColor(2, redPx - 120, grnPx - 50, bluePx - 5);
    strip->setPixelColor(3, redPx - 60, grnPx - 35, bluePx - 2);
    strip->setPixelColor(4, redPx, grnPx, bluePx);
    strip->setPixelColor(5, redPx, grnPx, bluePx);
    strip->setPixelColor(6, redPx, halfGrn, bluePx);
    strip->setPixelColor(7, redPx, grnHigh, bluePx);
    strip->show();
    delay(fDelay);
  }
  for (int grnPx = grnLow; grnPx < grnHigh; grnPx++) {
    int halfGrn = grnHigh - ((grnHigh - grnPx) / 2);
    int darkGrn = grnPx - 70;
    darkGrn = constrain(darkGrn, 5, 255);
    strip->setPixelColor(0, redPx - 180, darkGrn, 0);
    strip->setPixelColor(1, redPx - 180, darkGrn, 0);
    strip->setPixelColor(2, redPx - 120, grnPx - 50, bluePx - 5);
    strip->setPixelColor(3, redPx - 60, grnPx - 35, bluePx - 2);
    strip->setPixelColor(4, redPx, grnPx, bluePx);
    strip->setPixelColor(5, redPx, grnPx, bluePx);
    strip->setPixelColor(6, redPx, halfGrn, bluePx);
    strip->setPixelColor(7, redPx, grnHigh, bluePx);
    strip->show();
    delay(fDelay);
  }
}

// fire animation
void NeoCandle::on(int f) {
  fRep = f * 1000;
  int grnPx = grnHigh - 6;
  strip->setPixelColor(0, redPx - 180, grnPx - 70, 0);
  strip->setPixelColor(1, redPx - 180, grnPx - 70, 0);
  strip->setPixelColor(2, redPx - 120, grnPx - 50, bluePx - 5);
  strip->setPixelColor(3, redPx - 60, grnPx - 35, bluePx - 2);
  strip->setPixelColor(4, redPx, grnPx, bluePx);
  strip->setPixelColor(5, redPx, grnPx, bluePx);
  strip->setPixelColor(6, redPx, grnPx, bluePx);
  strip->setPixelColor(7, redPx, grnHigh, bluePx);
  strip->show();
  delay(fRep);
}

void NeoCandle::burn(int f) {
  fRep = f * 8;
  fDelay = burnDelay;
  for (int var = 0; var < fRep; var++) {
    fire(burnLow);
  }
}

void NeoCandle::flicker(int f) {
  fRep = f * 8;
  fDelay = burnDelay;
  fire(burnLow);
  fDelay = flickDelay;
  for (int var = 0; var < fRep; var++) {
    fire(flickLow);
  }
  fDelay = burnDelay;
  fire(burnLow);
  fire(burnLow);
  fire(burnLow);
}

void NeoCandle::flutter(int f) {
  fRep = f * 8;
  fDelay = burnDelay;
  fire(burnLow);
  fDelay = flickDelay;
  fire(flickLow);
  fDelay = flutDelay;
  for (int var = 0; var < fRep; var++) {
    fire(flutLow);
  }
  fDelay = flickDelay;
  fire(flickLow);
  fire(flickLow);
  fDelay = burnDelay;
  fire(burnLow);
  fire(burnLow);
}
