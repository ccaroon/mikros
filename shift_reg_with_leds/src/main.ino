const int latchPin = 8;
const int clockPin = 12;
const int dataPin  = 11;

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
    lightInSequence();
}

int greenLed = 0;
int blueLed  = 7;
void lightInSequence() {
    byte greenData = 0;
    byte blueData  = 0;
    byte data[2];

    bitWrite(greenData, greenLed, HIGH);
    bitWrite(blueData,  blueLed, HIGH);
    
    data[0] = blueData;
    data[1] = greenData;
    sendData(data, 2);

    delay(750);

    greenLed++;
    if (greenLed == 8) {
        greenLed = 0;
    }

    blueLed--;
    if (blueLed < 0) {
        blueLed = 7;
    }
}

void helloWorld() {
  // count from 0 to 255 and display the number 
  // on the LEDs
  for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(500);
  }
}