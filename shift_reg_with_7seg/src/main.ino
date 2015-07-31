const int latchPin = 8;
const int clockPin = 12;
const int dataPin  = 11;

void closeLatch() {
    digitalWrite(latchPin, LOW);
}

void openLatch() {
    digitalWrite(latchPin, HIGH);
}

void sendData(byte data) {
    closeLatch();
    shiftOut(dataPin, clockPin, MSBFIRST, data);
    openLatch();
}

void setup() {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);

    byte data = 0;
    // bitWrite(data, 1, LOW);
    // bitWrite(data, 2, LOW);
    // bitWrite(data, 3, LOW);
    sendData(data);
}


void loop() {
}
