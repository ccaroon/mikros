#include <SPI.h>
#include <Wire.h>
#include "TinyScreen.h"
#include "TinyJoystick.h"

TinyScreen   display  = TinyScreen(0);
TinyJoystick joystick = TinyJoystick();

uint8_t currentX = 0;
uint8_t currentY = 0;

void setup() {
    Serial.begin(9600);
    display.begin();

    // display.setFont(liberationSans_10ptFontInfo);
    // display.fontColor(,0x00);
    // display.print("etch-a-sketch");

    reset();
}

void reset() {
    display.drawRect(0,0,96,64,1,0xFF);

    currentX = 48;
    currentY = 32;
    display.goTo(currentX, currentY);
}

void loop() {
    bool cursorMoved = false;

    joystick.read();

    if (joystick.leftButtonPressed()) {
        reset();
    }
    else {
    // Left - Horizonal
        Location left  = joystick.getLeftStick();
        // Right - Vertical
        Location right = joystick.getRightStick();

        if (left.x > 200) {
            currentX++;
            cursorMoved = true;
        }
        else if (left.x < -200) {
            currentX--;
            cursorMoved = true;
        }

        if (right.y > 200) {
            currentY--;
            cursorMoved = true;
        }
        else if (right.y < -200) {
            currentY++;
            cursorMoved = true;
        }

        if (cursorMoved) {
            display.drawPixel(currentX, currentY, 0x00);
        }
    }

    delay(50);
}
