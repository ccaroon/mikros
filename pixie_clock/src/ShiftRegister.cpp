#include <Arduino.h>
#include "ShiftRegister.h"

void ShiftRegister::init() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
}

void ShiftRegister::closeLatch() {
    digitalWrite(latchPin, LOW);
}

void ShiftRegister::openLatch() {
    digitalWrite(latchPin, HIGH);
}

void ShiftRegister::sendData(byte *data, uint8_t len) {
    closeLatch();

    for (uint8_t i = 0; i < len; i++) {
        shiftOut(dataPin, clockPin, MSBFIRST, data[i]);
    }
    
    openLatch();
}
