#include <stdint.h>

#include "Arduboy.h"

const char gameName[6] = "nomis";

// Triangle W&H
const uint8_t triWidth  = 20;
const uint8_t triHeight = 15;

const uint16_t toneDuration = 375;

const uint8_t seqSize = 255;

class Nomis {
public:

    Nomis();

    void begin();
    void newGame();
    void nextLevel();
    void playSequence();
    void readSequence();
    void displayLogo();
    void displayLevel();
    void displaySuccess();
    void displayFail();

private:
    uint8_t level = 1;
    uint8_t sequence[seqSize];
    Arduboy arduboy;
    
    void drawUp();
    void drawDown();
    void drawLeft();
    void drawRight();
    void drawAButton();
    void drawBButton();
};
