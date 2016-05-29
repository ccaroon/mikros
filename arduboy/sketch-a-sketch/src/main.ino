#include "Arduboy.h"

#define MIN_X 1
#define MAX_X 128-2
#define MIN_Y 1
#define MAX_Y 64-2
#define BLACK 0
#define WHITE 1

Arduboy arduboy;

bool    drawingOn = true;
uint8_t currentX = 64;
uint8_t currentY = 32;
uint8_t previousX = 64;
uint8_t previousY = 32;

void reset() {
    currentX = 64;
    currentY = 32;
    previousX = 64;
    previousY = 32;
    drawingOn = true;

    arduboy.clear();
    arduboy.drawRect(0, 0, 128, 64, WHITE);
    arduboy.drawPixel(currentX, currentY, WHITE);
    arduboy.display();
}

void setup() {
    arduboy.begin();
    arduboy.setFrameRate(15);

    reset();
}

void loop() {
    bool cursorMoved = false;

    if (!arduboy.nextFrame()) {
        return;
    }

    // Clear the Screen
    if (arduboy.pressed(A_BUTTON + B_BUTTON)) {
        arduboy.tunes.tone(255, 250);
        reset();
    }
    else if (arduboy.pressed(A_BUTTON)) {
        drawingOn = false;
    }
    else if (arduboy.pressed(B_BUTTON)) {
        drawingOn = true;
    }
    else {
        previousX = currentX;
        previousY = currentY;

        // Left/Right - Horizonal
        if (arduboy.pressed(RIGHT_BUTTON) && currentX < MAX_X) {
            currentX++;
            cursorMoved = true;
        }
        else if (arduboy.pressed(LEFT_BUTTON) && currentX > MIN_X) {
            currentX--;
            cursorMoved = true;
        }
        // Up/Down - Vertical
        else if (arduboy.pressed(UP_BUTTON) && currentY > MIN_Y) {
            currentY--;
            cursorMoved = true;
        }
        else if (arduboy.pressed(DOWN_BUTTON) && currentY < MAX_Y) {
            currentY++;
            cursorMoved = true;
        }

        if (cursorMoved && drawingOn) {
            arduboy.drawPixel(currentX, currentY, WHITE);
            arduboy.display();
        }
        else if (cursorMoved && !drawingOn) {
            uint8_t color = arduboy.getPixel(previousX, previousY);
            arduboy.drawPixel(previousX, previousY, !color);

            color = arduboy.getPixel(currentX, currentY);
            arduboy.drawPixel(currentX, currentY, !color);

            arduboy.display();
        }
    }

    delay(50);
}
