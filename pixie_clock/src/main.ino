#include "Arduino.h"
#include "Wire.h"

#include "RTClib.h" // platformio lib install 83 (Adafruit)

#include "SevenSegmentDisplay.h"
#include "ShiftRegister.h"

RTC_DS1307 rtc;
// -----------------------------------------------------------------------------
void setup() {
    Wire.begin();
    rtc.begin();
    Serial.begin(9600);

    if (! rtc.isrunning()) {
        // following line sets the RTC to the date & time this sketch was compiled
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        // This line sets the RTC with an explicit date & time, for example to set
        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
}
// -----------------------------------------------------------------------------
void loop() {
    byte data[4];
    unsigned char digits[2] = {0,0};

    DateTime now = rtc.now();

    getDigits(now.hour(), digits);
    data[0] = DIGITS[digits[0]];
    data[1] = DIGITS[digits[1]];

    digits[0] = 0; digits[1] = 0;
    getDigits(now.minute(), digits);
    data[2] = DIGITS[digits[0]];
    data[3] = DIGITS[digits[1]];
    sendData(data, 4);

    // char date_str[21];    
    // sprintf(date_str, "%02d/%02d/%04d @ %02d:%02d:%02d", now.month(), now.day(), now.year(), now.hour(), now.minute(), now.second());
    // Serial.println(date_str);

    delay(1000);
}
// -----------------------------------------------------------------------------
void getDigits(unsigned char value, unsigned char* digits) {
    unsigned char i = 1;

    do {
        digits[i--] = value % 10;
        value /= 10;
    } while (value);

}
