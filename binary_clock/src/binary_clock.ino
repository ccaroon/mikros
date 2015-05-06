#include "Charliplexing.h"
#include "RTCLIb.h"

#include "bc_lib.h"

DS1339 RTC = DS1339();

void setup() {
    RTC.start();
    LedSign::Init();
    LedSign::Clear(0);

    // Turn on unused lines?
    // LedSign::Horizontal(0, 2);
    // LedSign::Horizontal(1, 2);
    // LedSign::Horizontal(2, 2);

    // LedSign::Horizontal(7, 2);
    // LedSign::Horizontal(8, 2);
}

void loop() {
    RTC.readTime();

    updateTime(HOURS_PLACE,   (int)RTC.getHours());
    updateTime(MINUTES_PLACE, (int)RTC.getMinutes());
    updateTime(SECONDS_PLACE, (int)RTC.getSeconds());

    delay(750);
}
