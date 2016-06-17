#include "nomis.h";

Nomis nomis;

void setup() {
    nomis.begin();
    nomis.newGame();
}

bool playerTurn = false;
void loop() {
    if (!nomis.ready()) {
        return;
    }

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
