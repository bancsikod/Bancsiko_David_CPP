//
// Created by David on 10/14/2021.
//

#include "Point.h"

int Point::counter{0};

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
    counter++;
}

Point::Point(const Point& cpy) : x(cpy.x), y(cpy.y){
    counter++;
}

Point::~Point() {
    counter--;
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

int Point::getCounter() {
    return counter;
}

