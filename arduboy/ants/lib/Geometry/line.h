#ifndef __LINE_H__
#define __LINE_H__

#include "point.h"
#include "rectangle.h"

class Line {
public:
    Line(Point&, Point&);

    Point intersectLine(Line&);
    bool intersectRect(Rectangle&);

    Point p1;
    Point p2;
private:
};

#endif
