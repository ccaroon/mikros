#include "point.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point (uint8_t x, uint8_t y) {
    this->x = x;
    this->y = y;
}

Point& Point::operator=(const Point& source) {
    if (this != &source) {
        this->x = source.x;
        this->y = source.y;
    }

    return(*this);
}

bool Point::operator==(const Point& otherPoint) {
    bool areEqual = false;

    if (this->x == otherPoint.x && this->y == otherPoint.y) {
        areEqual = true;
    }

    return (areEqual);
};

bool Point::operator!=(const Point& otherPoint) {
    bool areNotEqual = false;

    if (this->x != otherPoint.x || this->y != otherPoint.y) {
        areNotEqual = true;
    }

    return (areNotEqual);
};
