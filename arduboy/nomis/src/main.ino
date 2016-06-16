// #include "Arduboy.h"
// Arduboy arduboy;

#include "nomis.h";

Nomis nomis;

void setup() {
    nomis.begin();
    nomis.newGame();
}

void loop() {
    if (!arduboy.nextFrame()) {
        return;
    }

    nomis.displayLevel(level);
    delay(750);

    nomis.playSequence();
    nomis.nextLevel();

    if (level >= 25) {
        nomis.displaySuccess();
        delay(750);
        nomis.newGame();
    }
    delay(2500);
}
