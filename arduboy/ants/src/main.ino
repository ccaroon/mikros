#include "Arduboy.h"
#include "point.h"
#include "line.h"

Arduboy arduboy;

void setup() {
    arduboy.begin();
    arduboy.setFrameRate(15);
    arduboy.clear();
}

void loop() {
    if (!arduboy.nextFrame()) {
        return;
    }

    Point p1(random(128), random(64));
    Point p2(random(128), random(64));
    Line l(p1,p2);

    arduboy.drawLine(l.p1.x, l.p1.y, l.p2.x, l.p2.y, 1);
    // arduboy.drawPixel(x.x, x.y, 1);
    arduboy.display();

    delay(10);
}
