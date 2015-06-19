#include <SPI.h>
#include <Wire.h>
#include "TinyScreen.h"
#include "TinyJoystick.h"

#define MIN_X 2 
#define MAX_X TinyScreen::xMax-3
#define MIN_Y 2
#define MAX_Y TinyScreen::yMax-3

TinyScreen   display  = TinyScreen(0);
TinyJoystick joystick = TinyJoystick();

bool    screenOn = true;
uint8_t currentX = 0;
uint8_t currentY = 0;

void setup() {
    // Serial.begin(9600);

    display.begin();
    // display.setFont(liberationSans_10ptFontInfo);
    // display.fontColor(,0x00);
    // display.print("etch-a-sketch");

    // Center of display
    currentX = 47;
    currentY = 31;
    display.goTo(currentX, currentY);

    reset();
}

void reset() {
    // Frame
    display.drawRect(0,0,TinyScreen::xMax,TinyScreen::yMax,    0,0x03);
    display.drawRect(1,1,TinyScreen::xMax-2,TinyScreen::yMax-2,0,0x03);

    // Background
    display.drawRect(2,2,TinyScreen::xMax-4,TinyScreen::yMax-4,1,48,48,48);
}

void loop() {
    bool cursorMoved = false;

    joystick.read();

    if (joystick.leftButtonPressed()) {
        reset();
    }
    else if (joystick.rightButtonPressed()) {
        if (screenOn) {
            display.off();
            screenOn = false;
        }
        else {
            display.on();
            screenOn = true;
        }
    }
    else {
        // Left - Horizonal
        Location left = joystick.getLeftStick();
        if (left.x > 200 && currentX < MAX_X) {
            currentX++;
            cursorMoved = true;
        }
        else if (left.x < -200 && currentX > MIN_X) {
            currentX--;
            cursorMoved = true;
        }

        // Right - Vertical
        Location right = joystick.getRightStick();
        if (right.y > 200 && currentY > MIN_Y) {
            currentY--;
            cursorMoved = true;
        }
        else if (right.y < -200 && currentY < MAX_Y) {
            currentY++;
            cursorMoved = true;
        }

        if (cursorMoved) {
            display.drawPixel(currentX, currentY, 0x00);
        }
    }

    delay(50);
}
