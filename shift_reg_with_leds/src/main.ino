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
}

int led1 = 3;
int led2 = 4;
bool reverse = false;
void loop() {
    byte data = 0;

    bitWrite(data, led1, HIGH);
    bitWrite(data, led2, HIGH);
    sendData(data);
    delay(100);
    bitWrite(data, led1, LOW);
    bitWrite(data, led2, LOW);
    sendData(data);

    if (reverse) {
        if (led1 == 3 && led2 == 4) {
            reverse = false;
            led1--;
            led2++;
        }
        else {
            led1++;
            led2--;
        }
    }
    else {
        if (led1 == 0 && led2 == 7) {
            reverse = true;
            led1++;
            led2--;
        }
        else {
            led1--;
            led2++;
        }
    }

}
