#include <stdint.h>

#include "Arduboy.h"

const char gameName[6] = "nomis";

// Triangle W&H
const uint8_t triWidth  = 20;
const uint8_t triHeight = 15;

const uint16_t toneDuration = 375;

const uint8_t seqSize = 255;

const int upFreq    = 512;
const int rightFreq = 1024;
const int downFreq  = 1536;
const int leftFreq  = 2048;
const int aFreq     = 2560;
const int bFreq     = 3072;

enum class Button : uint8_t {
    NONE,
    UP,
    RIGHT,
    DOWN,
    LEFT,
    A,
    B
};

class Nomis {
public:

    Nomis();

    void begin();
    void newGame();
    void nextLevel();
    uint8_t getLevel() {return level;};
    void playSequence();
    Button checkForButtonPress();
    void displayLogo();
    void displayLevel();
    void displaySuccess();
    void displayFail();
    void displayProgress();
    bool ready();
    void drawButton(Button);
    bool correctButtonPressed(Button);
    bool sequenceComplete();
    void resetLevel();
    bool menu();

private:
    uint8_t level = 1;
    uint8_t buttonIndex = 0;
    Button sequence[seqSize];
    Arduboy arduboy;

    void drawUp();
    void drawDown();
    void drawLeft();
    void drawRight();
    void drawAButton();
    void drawBButton();
};
