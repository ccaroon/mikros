#ifndef __MULTIFUNCTION_H
#define __MULTIFUNCTION_H

#include <Adafruit_CircuitPlayground.h>
#include <LowPower.h>
#include <stdint.h>

#define TILT_COLOR 0x00FF77

#define ACTION_COLORLOOP 0
#define ACTION_TILT 1
#define ACTION_DISPLAYTEMP 2

class MultiFunction {

  public:
    void begin();
    void loop();

  private:
    uint8_t currentFunction = ACTION_TILT;

    void colorLoop();
    void displayTemp();
    void tilt();

    void setAllColor(uint32_t);
};

#endif
