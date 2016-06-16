#include "nomis.h"

Nomis::Nomis() {}

void Nomis::begin() {
    arduboy.beginNoLogo();
    arduboy.initRandomSeed();
}

void Nomis::newGame() {
    level = 1;
    for (uint8_t i = 0; i < seqSize; i++) {
        sequence[i] = random(6)+1;
    }

    displayLogo();    
}

void Nomis::nextLevel() {
    level++;
}

void Nomis::playSequence() {
    for (uint8_t i = 0; i < level; i++) {
        arduboy.clear();
        switch(sequence[i]) {
            case 1:
                nomis.drawUp();
                break;
            case 2:
                nomis.drawRight();
                break;
            case 3:
                nomis.drawDown();
                break;
            case 4:
                nomis.drawLeft();
                break;
            case 5:
                nomis.drawAButton();
                break;
            case 6:
                nomis.drawBButton();
                break;
        };
        arduboy.display();
        delay(500);
    }
}


void Nomis::readSequence() {
}

void Nomis::displayLogo() {
    uint8_t red = 255;
    uint8_t blue = 0;
    arduboy.setTextSize(3);


    for(uint8_t i = 0; i < 6; i++) {
        arduboy.clear();
        arduboy.setCursor(30+(i*16),20);
        arduboy.print(gameName[i]);
        arduboy.setRGBled(red, 0, blue);
        arduboy.display();

        if (red > 0) {
            red = 0;
            blue = 255;
        } else {
            red = 255;
            blue = 0;
        }

        if (i < 5) {
            delay(500);
        }

    }

    arduboy.clear();
    arduboy.setCursor(20,20);
    arduboy.print(gameName);
    arduboy.display();

    arduboy.setRGBled(255, 0, 255);

    delay(2000);
}

void Nomis::displayLevel(uint8_t number) {
    char numStr[4];
    sprintf(numStr, "%03d", number);

    arduboy.clear();
    arduboy.setTextSize(3);

    arduboy.setCursor(20,10);
    arduboy.print("Level");

    arduboy.setCursor(42, 35);
    arduboy.print(numStr);

    arduboy.display();
}

void Nomis::displayFail() {
    arduboy.clear();
    arduboy.setTextSize(3);

    arduboy.setCursor(10,20);
    arduboy.print("Failed!");

    // I gots me on of them messed-up Arduboy with the RGB LED all backwards
    // and stuff so Red == Blue and Blue == Red and Green don't work
    arduboy.setRGBled(0, 0, 255);
    arduboy.display();
}

void Nomis::displaySuccess() {
    arduboy.clear();
    arduboy.setTextSize(3);

    arduboy.setCursor(2,20);
    arduboy.print("Correct!");

    // I gots me on of them messed-up Arduboy with the RGB LED all backwards
    // and stuff so Red == Blue and Blue == Red and Green don't work
    arduboy.setRGBled(255, 0, 0);
    arduboy.display();
}

// Private Methods

void Nomis::drawUp() {
    uint8_t x = 30;
    uint8_t y = 5;
    arduboy.fillTriangle(x, y, x-(triWidth/2), y+triHeight, x+(triWidth/2), y+triHeight, 1);
    arduboy.tunes.tone(512, toneDuration);
}

void Nomis::drawRight() {
    uint8_t x = 45 + triHeight;
    uint8_t y = 23 + (triWidth/2);
    arduboy.fillTriangle(x, y, x-triHeight, y+(triWidth/2), x-triHeight, y-(triWidth/2), 1);
    arduboy.tunes.tone(1024, toneDuration);
}

void Nomis::drawDown() {
    uint8_t x = 30;
    uint8_t y = 60;
    arduboy.fillTriangle(x, y, x-(triWidth/2), y-triHeight, x+(triWidth/2), y-triHeight, 1);
    arduboy.tunes.tone(1536, toneDuration);
}

void Nomis::drawLeft() {
    uint8_t x = 15 - triHeight;
    uint8_t y = 23 + (triWidth/2);
    arduboy.fillTriangle(x, y, x+triHeight, y+(triWidth/2), x+triHeight, y-(triWidth/2), 1);
    arduboy.tunes.tone(2048, toneDuration);
}

void Nomis::drawAButton() {
    arduboy.fillCircle(90, 40, 10, 1);
    arduboy.tunes.tone(2560, toneDuration);
}

void Nomis::drawBButton() {
    arduboy.fillCircle(116, 32, 10, 1);
    arduboy.tunes.tone(3072, toneDuration);
}

    // // Red Buttons
    // if (arduboy.pressed(A_BUTTON)) {
    //     arduboy.clear();
    //     drawAButton();
    //     arduboy.display();
    // } else if (arduboy.pressed(B_BUTTON)) {
    //     arduboy.clear();
    //     drawBButton();
    //     arduboy.display();
    // }
    // // Left/Right - Horizonal
    // else if (arduboy.pressed(RIGHT_BUTTON)) {
    //     arduboy.clear();
    //     drawRight();
    //     arduboy.display();
    // }
    // else if (arduboy.pressed(LEFT_BUTTON)) {
    //     arduboy.clear();
    //     drawLeft();
    //     arduboy.display();
    // }
    // // Up/Down - Vertical
    // else if (arduboy.pressed(UP_BUTTON)) {
    //     arduboy.clear();
    //     drawUp();
    //     arduboy.display();
    // }
    // else if (arduboy.pressed(DOWN_BUTTON)) {
    //     arduboy.clear();
    //     drawDown();
    //     arduboy.display();
    // }
