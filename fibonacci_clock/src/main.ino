#include "RTCLib.h"
#include "TinyScreen.h"
#include <SPI.h>
#include <Wire.h>
#include "main.h"

TinyScreen display = TinyScreen(0);
DS1339 RTC         = DS1339();

void drawSquare(const FibSquare* s, uint8_t color) {
    display.drawRect(s->x, s->y, s->units*UNIT_SIZE, s->units*UNIT_SIZE, 1, colorMap[color]);
    display.drawRect(s->x, s->y, s->units*UNIT_SIZE, s->units*UNIT_SIZE, 0, 0x00);
}

void numberToFibSquares(uint8_t number, uint8_t* squares, uint8_t color) {
    uint8_t i, choice;
    
    // TODO: simplify this
    switch (number) {
        case 1:
            choice = rand() % 2; // Actual number of choices
            break;
        case 2:
            choice = rand() % 2; // Actual number of choices
            break;
        case 3:
            choice = rand() % 3; // Actual number of choices
            break;
        case 4:
            choice = rand() % 3; // Actual number of choices
            break;
        case 5:
            choice = rand() % 3; // Actual number of choices
            break;
        case 6:
            choice = rand() % 4; // Actual number of choices
            break;
        case 7:
            choice = rand() % 2; // Actual number of choices
            break;
        case 8:
            choice = rand() % 3; // Actual number of choices
            break;
        case 9:
            choice = rand() % 3; // Actual number of choices
            break;
        case 10:
            choice = rand() % 2; // Actual number of choices
            break;
        case 11:
            choice = rand() % 2; // Actual number of choices
            break;
        case 12:
            choice = 0; // Actual number of choices
            break;
    }

    if (number > 0) {
        for (i = 0; i < MAX_COMBOS; i++) {
            if (fibMap[number][choice][i] != EMPTY) {
                squares[fibMap[number][choice][i]] += color;
            }
        }
    }
}

void setup() {
    Wire.begin();
    RTC.start();
    display.begin();
    Serial.begin(9600);

    srand(analogRead(0));
}

void printSquares(uint8_t* squares) {
    for (uint8_t i = 0; i < 5; i++) {
        Serial.print("(");
        Serial.print(squares[i]);
        Serial.print(") ");
    }
    Serial.println("");
}

void loop() {
    uint8_t hours, minutes;
    uint8_t squares[5];

    RTC.readTime();

    hours = RTC.getHours();
    if (hours > 12) {
        hours -= 12;
    }
    minutes = RTC.getMinutes();
    minutes /= 5;

    Serial.println(hours);
    Serial.println(minutes);

    memset(squares, 0, 5*sizeof(uint8_t));
    numberToFibSquares(hours,   squares, COLOR_HOURS);
    numberToFibSquares(minutes, squares, COLOR_MINUTES);

    drawSquare(&one,      squares[ONE]);
    drawSquare(&onePrime, squares[ONE_PRIME]);
    drawSquare(&two,      squares[TWO]);
    drawSquare(&three,    squares[THREE]);
    drawSquare(&five,     squares[FIVE]);

    delay(60000);
}
