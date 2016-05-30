#include <stdint.h>

#ifndef __POINT_H__
#define __POINT_H__

class Point {
public:
    Point();
    Point(uint8_t, uint8_t);

    bool operator==(const Point&);
    bool operator!=(const Point&);
    Point& operator=(const Point&);

    uint8_t x, y;
private:

};

#endif
