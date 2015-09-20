#include "ShiftRegister.h"

void closeLatch() {
    digitalWrite(latchPin, LOW);
}

void openLatch() {
    digitalWrite(latchPin, HIGH);
}

void sendData(byte *data, uint8_t len) {
    closeLatch();

    for (uint8_t i = 0; i < len; i++) {
        shiftOut(dataPin, clockPin, MSBFIRST, data[i]);
    }
    
    openLatch();
}