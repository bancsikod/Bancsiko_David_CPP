//
// Created by David on 09/30/2021.
//

#ifndef LAB02_01_FUNCTION_H
#define LAB02_01_FUNCTION_H

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Point{
    int x,y;
public:
    Point(int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
};

double distance(const Point& x, const Point& y);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
int compare (const void * a, const void * b);

#endif //LAB02_01_FUNCTION_H
