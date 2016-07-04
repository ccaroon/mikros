#include "nomis.h"

Nomis::Nomis() {}

void Nomis::begin() {
    arduboy.beginNoLogo();
    arduboy.initRandomSeed();
}

bool Nomis::menu() {
    Button b = Button::NONE;
    displayLogo();

    arduboy.setCursor(15, 35);
    arduboy.setTextSize(1);
    arduboy.print("Press A to Start");
    arduboy.display();

    while (b != Button::A) {
        b = checkForButtonPress();
    }

    return true;
}

void Nomis::newGame() {
    level = 1;
    buttonIndex = 0;
    for (uint8_t i = 0; i < seqSize; i++) {
        sequence[i] = static_cast<Button>(random(6)+1);
    }
}

void Nomis::nextLevel() {
    level++;
    buttonIndex = 0;
}

void Nomis::playSequence() {
    for (uint8_t i = 0; i < level; i++) {
        drawButton(sequence[i]);
    }
}

void Nomis::drawButton(Button b) {
    arduboy.clear();
    switch(b) {
        case Button::A:
            drawAButton();
            break;
        case Button::B:
            drawBButton();
            break;
        case Button::UP:
            drawUp();
            break;
        case Button::RIGHT:
            drawRight();
            break;
        case Button::DOWN:
            drawDown();
            break;
        case Button::LEFT:
            drawLeft();
            break;
        case Button::NONE:
            break;
    }
    arduboy.display();
    delay(500);
}

void Nomis::resetLevel() {
    buttonIndex = 0;
}

bool Nomis::sequenceComplete() {
    return buttonIndex == level ? true : false;
}

bool Nomis::correctButtonPressed(Button b) {
    bool correct = sequence[buttonIndex] == b ? true : false;
    if (correct) {
        buttonIndex++;
    }

    return correct;
}

Button Nomis::checkForButtonPress() {
    if (arduboy.pressed(UP_BUTTON)) {
        return Button::UP;
    } else if (arduboy.pressed(DOWN_BUTTON)) {
        return Button::DOWN;
    } else if (arduboy.pressed(LEFT_BUTTON)) {
        return Button::LEFT;
    } else if (arduboy.pressed(RIGHT_BUTTON)) {
        return Button::RIGHT;
    } else if (arduboy.pressed(A_BUTTON)) {
        return Button::A;
    } else if (arduboy.pressed(B_BUTTON)) {
        return Button::B;
    } else {
        return Button::NONE;
    }
}

void Nomis::displayLogo() {
    uint8_t red = 255;
    uint8_t blue = 0;
    int     baseFreq = 512;
    arduboy.setTextSize(3);

    for(uint8_t i = 0; i < 6; i++) {
        arduboy.clear();
        arduboy.setCursor(30+(i*15),5);
        arduboy.print(gameName[i]);
        arduboy.setRGBled(red, 0, blue);
        arduboy.display();

        arduboy.tunes.tone(baseFreq, toneDuration);
        baseFreq += 512;

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
    arduboy.setCursor(20,5);
    arduboy.print(gameName);
    arduboy.display();

    arduboy.setRGBled(255, 0, 255);

    delay(1000);
}

void Nomis::displayLevel() {
    char numStr[4];
    sprintf(numStr, "%03d", level);

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
    arduboy.setTextSize(2);

    arduboy.setCursor(8,20);
    arduboy.print("Try Again!");

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

void Nomis::displayProgress() {
    char text[10];

    sprintf(text, "%d/%d", buttonIndex, level);
    arduboy.clear();
    arduboy.setTextSize(2);
    arduboy.setCursor(45,5);
    arduboy.print(text);
    arduboy.display();
}

bool Nomis::ready() {
    return arduboy.nextFrame();
}

// Private Methods
void Nomis::drawUp() {
    uint8_t x = 30;
    uint8_t y = 5;
    arduboy.fillTriangle(x, y, x-(triWidth/2), y+triHeight, x+(triWidth/2), y+triHeight, 1);
    arduboy.tunes.tone(upFreq, toneDuration);
}

void Nomis::drawRight() {
    uint8_t x = 45 + triHeight;
    uint8_t y = 23 + (triWidth/2);
    arduboy.fillTriangle(x, y, x-triHeight, y+(triWidth/2), x-triHeight, y-(triWidth/2), 1);
    arduboy.tunes.tone(rightFreq, toneDuration);
}

void Nomis::drawDown() {
    uint8_t x = 30;
    uint8_t y = 60;
    arduboy.fillTriangle(x, y, x-(triWidth/2), y-triHeight, x+(triWidth/2), y-triHeight, 1);
    arduboy.tunes.tone(downFreq, toneDuration);
}

void Nomis::drawLeft() {
    uint8_t x = 15 - triHeight;
    uint8_t y = 23 + (triWidth/2);
    arduboy.fillTriangle(x, y, x+triHeight, y+(triWidth/2), x+triHeight, y-(triWidth/2), 1);
    arduboy.tunes.tone(leftFreq, toneDuration);
}

void Nomis::drawAButton() {
    arduboy.fillCircle(90, 40, 10, 1);
    arduboy.tunes.tone(aFreq, toneDuration);
}

void Nomis::drawBButton() {
    arduboy.fillCircle(116, 32, 10, 1);
    arduboy.tunes.tone(bFreq, toneDuration);
}
