//
// Created by David on 09/30/2021.
//

#ifndef LAB02_01_FUNCTION_H
#define LAB02_01_FUNCTION_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <ctime>
#define TWOK 2001
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
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
bool myfunction(Point a, Point b);
void swapPointsDistance(Point &a, Point &b, double &x, double &y);
void sortPointsByDistance(Point* &points, double* &distances, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);

#endif //LAB02_01_FUNCTION_H
