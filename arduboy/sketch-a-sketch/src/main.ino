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
uint8_t currentColor = WHITE;

void reset() {
    currentX = 64;
    currentY = 32;
    previousX = 64;
    previousY = 32;

    arduboy.clear();
    arduboy.drawRect(0, 0, 128, 64, WHITE);
    arduboy.drawPixel(currentX, currentY, WHITE);

    drawingOn = true;
    arduboy.drawChar(1,1,'+',BLACK,WHITE,1);

    currentColor = WHITE;
    arduboy.drawChar(121,1,'W',BLACK,WHITE,1);

    arduboy.display();

    arduboy.setRGBled(255,0,255);
    delay(250);
    arduboy.setRGBled(0,0,0);
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
        if (drawingOn == true) {
            drawingOn = false;
            arduboy.drawChar(1,1,'-',BLACK,WHITE,1);
        }
        else {
            drawingOn = true;
            arduboy.drawChar(1,1,'+',BLACK,WHITE,1);
        }
        arduboy.display();
        delay(500);
    }
    else if (arduboy.pressed(B_BUTTON)) {
        if (currentColor == WHITE) {
            currentColor = BLACK;
            arduboy.drawChar(121,1,'B',BLACK,WHITE,1);
        }
        else {
            currentColor = WHITE;
            arduboy.drawChar(121,1,'W',BLACK,WHITE,1);
        }
        arduboy.display();
        delay(500);
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

        if (cursorMoved) {
            if (drawingOn) {
                arduboy.drawPixel(previousX, previousY, currentColor);
                arduboy.drawPixel(currentX, currentY, WHITE);
            }
            else {
                uint8_t color = arduboy.getPixel(previousX, previousY);
                arduboy.drawPixel(previousX, previousY, !color);

                color = arduboy.getPixel(currentX, currentY);
                arduboy.drawPixel(currentX, currentY, !color);
            }

            arduboy.display();
        }
    }

    delay(10);
}
