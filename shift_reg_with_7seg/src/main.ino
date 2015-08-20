#define SEG_A 3
#define SEG_B 4
#define SEG_C 6
#define SEG_D 7
#define SEG_E 5
#define SEG_F 2
#define SEG_G 1
#define SEG_DP 0

const int latchPin = 8;
const int clockPin = 12;
const int dataPin  = 11;

//             DCEBAFG.
#define ZERO  B00000011
#define ONE   B10101111
#define TWO   B01000101
//             DCEBAFG.
#define THREE B00100101

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

int pin = 0;
void loop() {
    byte data[1];

    data[0] = THREE;
    // bitWrite(data[0], pin++, 0);
    // sendData(data, 1);
    sendData(data, 1);
    // if (pin > 7) {
    //     pin = 0;
    // }

    delay(5000);
}
