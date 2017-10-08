#ifndef __MULTIFUNCTION_H
#define __MULTIFUNCTION_H

#include <Adafruit_CircuitPlayground.h>
#include <stdint.h>

#define TILT_COLOR 0x00FF77

// 0 = 0-10     blue
// 1 = 11-20    blue
// 2 = 21-30    blue
// 3 = 31-40    blue
// 4 = 41-50    blue/cyan
// 5 = 51-60    cyan
// 6 = 61-70    cyan/green
// 7 = 71-80    green/orange
// 8 = 81-90    orange/red
// 9 = 91-100   red
const uint32_t TempColorMap[10] = {0x0000FF, 0x0000FF, 0x0000FF, 0x0033FF,
                                   0x0055FF, 0x00FFFF, 0x00FF11, 0x77FF00,
                                   0xFF7700, 0xFF0000};

#define ACTION_COLORLOOP 0
#define ACTION_TILT 1
#define ACTION_DISPLAYTEMP 2

class MultiFunction {

  public:
    void begin();
    void loop();

  private:
    uint8_t currentFunction = ACTION_DISPLAYTEMP;

    void colorLoop();
    void displayTemp();
    void tilt();

    void setAllColor(uint32_t);
};

#endif
