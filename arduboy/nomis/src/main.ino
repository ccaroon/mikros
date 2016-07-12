#include "nomis.h"

Nomis nomis;

bool playerTurn = false;
bool inGame = false;
void setup() {
    nomis.begin();
}

void gameLoop() {
    if (playerTurn) {
        nomis.displayProgress();
        Button button = nomis.checkForButtonPress();

        if (button != Button::NONE) {
            nomis.drawButton(button);
            if (nomis.correctButtonPressed(button)) {
                if (nomis.sequenceComplete()) {
                    nomis.displaySuccess();
                    nomis.nextLevel();
                    playerTurn = false;
                    delay(1000);
                }
            } else {
                nomis.displayFail();
                nomis.resetLevel();
                delay(1000);
                playerTurn = false;
            }
        }
    } else {
        nomis.displayLevel();
        delay(750);
        nomis.playSequence();
        playerTurn = true;
    }
}

void menuLoop() {
    inGame = nomis.menu();
    nomis.newGame();
}

void loop() {
    if (!nomis.ready()) {
        return;
    }

    if (inGame) {
        gameLoop();
    } else {
        menuLoop();
    }
}
