#include "Charliplexing.h"
#include "alpha.h"

uint8_t computeXOffset(uint8_t x) {
    uint8_t xOffset = 0;

    switch (x) {
        case 0:
            xOffset = 0;
            break;
        case 1:
            xOffset = 3;
            break;
    }

    return(xOffset);
}

uint8_t computeYOffset(uint8_t y) {
    uint8_t yOffset = 0;

    switch (y) {
        case 0:
            yOffset = 0;
            break;
        case 1:
            yOffset = 3;
            break;
        case 2:
            yOffset = 6;
            break;
    }

    return(yOffset);
}

void ledsOn(const LEDPosition* leds, uint8_t size, uint8_t x, uint8_t y) {
    uint8_t i, xOffset, yOffset;

    xOffset = computeXOffset(x);
    yOffset = computeYOffset(y);

    for(i = 0; i < size; i++) {
        LedSign::Set(
            leds[i].x + xOffset,
            leds[i].y + yOffset
        );
    }
}

void drawLetter(char letter, uint8_t x, uint8_t y) {
    switch (letter) {
        case 'a':
        case 'A':
            ledsOn(LETTER_A, 6, x, y);
            break;
        case 'b':
        case 'B':
            ledsOn(LETTER_B, 5, x, y);
            break;
        case 'c':
        case 'C':
            ledsOn(LETTER_C, 7, x, y);
            break;
        default:
            break;
    }
}





















