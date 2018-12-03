#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "point.h"
#include "line.h"

class Rectangle {
public:
    Rectangle();
    Rectangle(const Point&, uint8_t, uint8_t);

    // Point   getOrigin();
    // uint8_t getWidth();
    // uint8_t getHeight();

    // bool lineIntersects(const Line&);
    Point origin;
    uint8_t width, height;
// private:
    Line top, right, bottom, left;
};


#endif
