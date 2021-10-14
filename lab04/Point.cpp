//
// Created by David on 10/14/2021.
//

#include "Point.h"

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getY() const {
    return this->y;
}

int Point::getX() const {
    return this->x;
}

//const az azt jelenti h a this x es yonjat nem lehet megmodositani
double Point::distanceTo(const Point& point)const {
    double dx = this->x - point.x;
    double dy = this->y - point.y;
    return sqrt(dx*dx + dy*dy);
}