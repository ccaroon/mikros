#include "rectangle.h"

Rectangle::Rectangle() {
    Rectangle(Point(0,0), 0, 0);
}
// -----------------------------------------------------------------------------
// a---------b
// |         |
// |         |
// c---------d
// -----------------------------------------------------------------------------
Rectangle::Rectangle(const Point& o, uint8_t w, uint8_t h) {
    this->origin = o;
    this->width  = w;
    this->height = h;

    // a -------- b
    this->top = Line(o, Point(o.x+w, o.y));

    // b -------- d
    this->right = Line(Point(o.x+w, o.y),   Point(o.x+w, o.y+h));

    // c -------- d
    this->bottom = Line(Point(o.x, o.y+h), Point(o.x+w,   o.y+h));

    // a -------- c
    this->left = Line(o, Point(o.x, o.y+h));
}

// bool Rectangle::lineIntersects(const Line& line) {
//     bool doesIntersect = false;
//
//     if (line.intersectionPoint(this->top)) {
//         doesIntersect = true;
//     }
//     else if (line.intersectionPoint(this->right)) {
//
//     }
//
//     // for (uint8_t i = 0; i < 4; i+=1) {
//     //     if (this->intersectLine(rect.sides[i])) {
//     //         doesIntersect = true;
//     //         break;
//     //     }
//     // }
//
//     return (doesIntersect);
// };
