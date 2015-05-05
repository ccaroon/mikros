// #include "Font.h"
#include "Figure.h"
#include "Charliplexing.h"
#include "RTCLIb.h"

DS1339 RTC = DS1339();

void setup() {
    RTC.start();
    LedSign::Init();
    LedSign::Clear(0);
}

void getDigits(int value, int* digits) {
    int i = 0;

    do {
        digits[i++] = value % 10;
        value /= 10; 
    } while (value);

}

void updateHour(int* digits) {
    
}

void loop() {
    int i;
    int hour, min, sec;
    int digits[2];
    RTC.readTime();

    i = 0;
    hour = RTC.getHours();
    getDigits(hour, digits);
    updateHour(digits);

    // Figure::Scroll90(digits[0], 0);
    // Figure::Scroll90(digits[1], 0);
    // seconds = RTC.getSeconds();

    // Figure::Scroll90(RTC.getHours(), 0);
    // Figure::Scroll90(RTC.getMinutes(), 0);
    // LedSign::Set(3,2,1);
    // Font::Draw((char)color, 0, 0, color);
    
    // color++;
    // if (color > 8) {
    //     color = 1;
    // }
    // delay(1000);

    // LedSign::Set(3,2,0);

    // for (int y = 0; y < 9; y++) {
    //     for (int x = 0; x < 6; x++) {
    //         LedSign::Set(x,y,1);
    //         delay(100);
    //         LedSign::Set(x,y,0);
    //     }
    // }

    // LedSign::Set(0,0,1);
    // LedSign::Set(5,8,1);

    // delay(1000);
}
