#include <stdint.h>

#include "point.h"
#include "line.h"

Line::Line() {
    Line(Point(0,0), Point(0,0));
}

Line::Line(const Point& p1, const Point& p2) {
    this->p1 = p1;
    this->p2 = p2;
}

Point Line::intersectionPoint(const Line& otherLine) {
    float s1X, s1Y, s2X, s2Y, iX, iY, s, t;
    Point i;

    s1X = this->p2.x - this->p1.x;
    s1Y = this->p2.y - this->p1.y;
    s2X = otherLine.p2.x - otherLine.p1.x;
    s2Y = otherLine.p2.y - otherLine.p1.y;

    s = (-s1Y * (this->p1.x - otherLine.p1.x) + s1X * (this->p1.y - otherLine.p1.y)) / (-s2X * s1Y + s1X * s2Y);
    t = ( s2X * (this->p1.y - otherLine.p1.y) - s2Y * (this->p1.x - otherLine.p1.x)) / (-s2X * s1Y + s1X * s2Y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
        iX = this->p1.x + (t * s1X);
        iY = this->p1.y + (t * s1Y);
        i = Point(iX, iY);
    }

    return (i);
};
