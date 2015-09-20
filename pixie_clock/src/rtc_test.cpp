#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#include "RTClib.h" // platformio lib install 83 (Adafruit)

RTC_DS1307 rtc;
LiquidCrystal lcd = LiquidCrystal(7, 8, 9, 10, 11, 12);

void init_rtc_test() {
    Wire.begin();
    rtc.begin();
    lcd.begin(16,2);

    if (! rtc.isrunning()) {
        // following line sets the RTC to the date & time this sketch was compiled
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        // This line sets the RTC with an explicit date & time, for example to set
        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }
    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void run_rtc_test() {
    char date_str[11];
    char time_str[8];

    DateTime now = rtc.now();
    
    sprintf(date_str, "%02d/%02d/%04d", now.month(), now.day(), now.year());
    sprintf(time_str, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

    lcd.setCursor(0,0);
    lcd.print(date_str);
    lcd.setCursor(0,1);
    lcd.print(time_str);
    delay(500);
}
