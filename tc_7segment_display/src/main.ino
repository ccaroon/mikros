#include <Wire.h>
#include "Tiny7SegmentDisplay.h"

Tiny7SegmentDisplay seg;

void setup()
{
    Wire.begin();
    seg.init();
}

void loop()
{
    for (int i = 0; i < 100; i++) {
        seg.printInt(i);
        delay(250);
    }

    seg.off();
    delay(1000);

    seg.setDecPoints(1,0);
    delay(1000);
    seg.setDecPoints(0,1);
    delay(1000);
    seg.setDecPoints(0,0);
    delay(1000);
}