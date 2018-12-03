#include "Arduboy.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"

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
    arduboy.drawPixel(p1.x, p1.y, random(2));

    Point p2(random(128), random(64));
    arduboy.drawPixel(p2.x, p2.y, random(2));

    Line l(p1,p2);
    arduboy.drawLine(l.p1.x, l.p1.y, l.p2.x, l.p2.y, random(2));

    Rectangle box(p1, random(128), random(64));
    arduboy.drawRect(box.origin.x, box.origin.y, box.width, box.height, random(2));

    arduboy.display();

    delay(50);
}
