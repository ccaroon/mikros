#include "Arduboy.h"

Arduboy arduboy;

const uint8_t MAX_X = 128;
const uint8_t MAX_Y = 64;

const char name[6] = "nomis";

// Triangle W&H
const uint8_t width = 20;
const uint8_t height = 15;

const uint16_t toneDuration = 375;

const uint8_t seqSize = 255;
uint8_t sequence[seqSize];

void setup() {
    arduboy.beginNoLogo();
    arduboy.initRandomSeed();

    for (uint8_t i = 0; i < seqSize; i++) {
        sequence[i] = random(6)+1;
    }
    // arduboy.clear();
    // drawUp();
    // drawDown();
    // drawRight();
    // drawLeft();
    // drawAButton();
    // drawBButton();
    // arduboy.display();

    // displayLevel(1);
    // delay(2000);
    // displayFail();
    // delay(2000);
    // displaySuccess();

    displayLogo();
}

void displayLogo() {
    uint8_t red = 255;
    uint8_t blue = 0;
    arduboy.setTextSize(3);


    for(uint8_t i = 0; i < 6; i++) {
        arduboy.clear();
        arduboy.setCursor(30+(i*16),20);
        arduboy.print(name[i]);
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

    // arduboy.clear();
    arduboy.setCursor(20,20);
    arduboy.print(name);
    arduboy.display();

    arduboy.setRGBled(255, 0, 255);

    delay(2000);
}

void displayLevel(uint8_t number) {
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

void displayFail() {
    arduboy.clear();
    arduboy.setTextSize(3);

    arduboy.setCursor(10,20);
    arduboy.print("Failed!");

    // I gots me on of them messed-up Arduboy with the RGB LED all backwards
    // and stuff so Red == Blue and Blue == Red and Green don't work
    arduboy.setRGBled(0, 0, 255);
    arduboy.display();
}

void displaySuccess() {
    arduboy.clear();
    arduboy.setTextSize(3);

    arduboy.setCursor(2,20);
    arduboy.print("Correct!");

    // I gots me on of them messed-up Arduboy with the RGB LED all backwards
    // and stuff so Red == Blue and Blue == Red and Green don't work
    arduboy.setRGBled(255, 0, 0);
    arduboy.display();
}

void drawUp() {
    uint8_t x = 30;
    uint8_t y = 5;
    arduboy.fillTriangle(x, y, x-(width/2), y+height, x+(width/2), y+height, 1);
    arduboy.tunes.tone(512, toneDuration);
}

void drawRight() {
    uint8_t x = 45 + height;
    uint8_t y = 23 + (width/2);
    arduboy.fillTriangle(x, y, x-height, y+(width/2), x-height, y-(width/2), 1);
    arduboy.tunes.tone(1024, toneDuration);
}

void drawDown() {
    uint8_t x = 30;
    uint8_t y = 60;
    arduboy.fillTriangle(x, y, x-(width/2), y-height, x+(width/2), y-height, 1);
    arduboy.tunes.tone(1536, toneDuration);
}

void drawLeft() {
    uint8_t x = 15 - height;
    uint8_t y = 23 + (width/2);
    arduboy.fillTriangle(x, y, x+height, y+(width/2), x+height, y-(width/2), 1);
    arduboy.tunes.tone(2048, toneDuration);
}

void drawAButton() {
    arduboy.fillCircle(90, 40, 10, 1);
    arduboy.tunes.tone(2560, toneDuration);
}

void drawBButton() {
    arduboy.fillCircle(116, 32, 10, 1);
    arduboy.tunes.tone(3072, toneDuration);
}

uint8_t level = 1;
void loop() {
    if (!arduboy.nextFrame()) {
        return;
    }

    displayLevel(level);
    delay(750);

    for (uint8_t i = 0; i < level; i++) {
        arduboy.clear();
        switch(sequence[i]) {
            case 1:
                drawUp();
                break;
            case 2:
                drawRight();
                break;
            case 3:
                drawDown();
                break;
            case 4:
                drawLeft();
                break;
            case 5:
                drawAButton();
                break;
            case 6:
                drawBButton();
                break;
        };
        arduboy.display();
        delay(500);
    }

    level++;
    if (level >= 25) {
        displaySuccess();
        level = 0;
    }
    delay(2500);
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
}
