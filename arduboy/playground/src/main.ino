#include "Arduboy.h"
#include "bitmaps.h"

Arduboy arduboy;

const uint8_t MAX_X = 128;
const uint8_t MAX_Y = 64;

uint8_t currentX = 64;
uint8_t currentY = 32;

void setup() {
    arduboy.beginNoLogo();
    arduboy.clear();

    arduboy.initRandomSeed();

    drawPlayer(currentX, currentY);
}

void drawPlayer(uint8_t x, uint8_t y) {
    arduboy.clear();
    arduboy.drawBitmap(x, y, player,  8, 8, 1);
    arduboy.display();
}

void loop() {
    if (!arduboy.nextFrame()) {
        return;
    }

    bool playerMoved = false;
    // Left/Right - Horizonal
    if (arduboy.pressed(RIGHT_BUTTON) && currentX < MAX_X) {
        currentX++;
        playerMoved = true;
    }
    else if (arduboy.pressed(LEFT_BUTTON) && currentX > 0) {
        currentX--;
        playerMoved = true;
    }
    // Up/Down - Vertical
    else if (arduboy.pressed(UP_BUTTON) && currentY > 0) {
        currentY--;
        playerMoved = true;
    }
    else if (arduboy.pressed(DOWN_BUTTON) && currentY < MAX_Y) {
        currentY++;
        playerMoved = true;
    }

    if (playerMoved) {
        drawPlayer(currentX, currentY);
    }
}
