//
// Created by David on 09/30/2021.
//

#include "function.h"

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "p1(" << x << "," << y << ")" << endl;
}

double distance(const Point& x,const Point& y) {
    double dx,dy,d;
    dx = x.getX() - y.getX();
    dy = x.getY() - y.getY();
    dx*=dx;
    dy*=dy;
    d = dx + dy;
    return sqrt(d);
}

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    auto *el = new double[6];
    el[0] = distance(a,b);
    el[1] = distance(a,c);
    el[2] = distance(a,d);
    el[3] = distance(b,c);
    el[4] = distance(b,d);
    el[5] = distance(c,d);


    sort(el, el+6);

    if(el[0] <= 0) return false;

    if (el[0] == el[3] && el[4] == el[5] && el[3] < el[4]) {
        return true;
    } else return false;
}