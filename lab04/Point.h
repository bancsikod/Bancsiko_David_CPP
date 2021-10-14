//
// Created by David on 10/14/2021.
//

#ifndef LAB04_POINT_H
#define LAB04_POINT_H
#define M 2000

#include <cmath>
#include <iostream>

using namespace std;

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const;
};

#endif //LAB04_POINT_H
