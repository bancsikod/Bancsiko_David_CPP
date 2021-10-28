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
    static int counter;
public:
    Point( int x=0, int y=0);
    Point(const Point&);
    ~Point();
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const;

    static int getCounter();
};

#endif //LAB04_POINT_H
