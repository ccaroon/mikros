// Connections
// 7-Segement Display (PIN) ---> Shift Register (PIN)
// --------------------------------------------------
// ### TOP
// * G   (1) ---> Q1 (1)
// * F   (2) ---> Q2 (2)
// * GND (3) ---> N/A (connected to GND)
// * A   (4) ---> Q3 (3)
// * B   (5) ---> Q4 (4)
// ### BOTTOM
// * E   (6) ---> Q5 (5)
// * D   (7) ---> Q6 (6)
// * GND (8) ---> N/A (connected to GND)
// * C   (9) ---> Q7 (7)
// * DP (10) ---> Q0 (15)

const uint8_t latchPin = 8;
const uint8_t clockPin = 12;
const uint8_t dataPin  = 11;

// CDEBAFG.
const byte digits[10] = {
    B00000011,
    B01101111,
    B10000101,
    B00100101,
    B01101001,
    B00110001,
    B00011001,
    B01100111,
    B00000001,
    B01100001
};

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

void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
}

void loop() {
    byte data[2];

    // unsigned long secs = millis() * 1000;
    // int digit1 = secs / 99;
    // int digit2 = secs % 99;

    // data[0] = digits[digit1];
    // data[1] = digits[digit2];
    // sendData(data, 2);
    // delay(1000);

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            data[0] = digits[i];
            data[1] = digits[j];
            sendData(data, 2);
            delay(1000);
        }
    }

    delay(5000);
}
