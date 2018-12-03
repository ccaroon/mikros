#ifndef __LINE_H__
#define __LINE_H__

#include "point.h"
// #include "rectangle.h"

class Line {
public:
    Line();
    Line(const Point&, const Point&);

    Point intersectionPoint(const Line&);

    Point p1;
    Point p2;
private:
};

#endif
