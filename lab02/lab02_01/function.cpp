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
    cout << "(" << x << ", " << y << ") ";
}

double distance(const Point& x, const Point& y) {
    double dx,dy,d;
    dx = x.getX() - y.getX();
    dy = x.getY() - y.getY();
    dx*=dx;
    dy*=dy;
    d = dx + dy;
    return sqrt(d);
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

void testIsSquare(const char * filename) {
    ifstream fptr(filename);
    if(!fptr) {
        cout << "file empty" << endl;
        return;
    }

    string line;
    while (getline(fptr,line)) {
        istringstream ss(line);
        int x, y;
        ss >> x >> y;
        Point p1(x,y);
        ss >> x >> y;
        Point p2(x,y);
        ss >> x >> y;
        Point p3(x,y);
        ss >> x >> y;
        Point p4(x,y);
//        cout << "p1 = ";
        p1.print();
//        cout << "p2 = ";
        p2.print();
//        cout << "p3 = ";
        p3.print();
//        cout << "p4 = ";
        p4.print();
        if(isSquare(p1,p2,p3,p4))
            cout << " => YES";
        else
            cout << " => NO";
        cout << endl;
    }
}

Point* createArray(int numPoints) {
    srand(time(0));

    Point* points = new Point[numPoints];
    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(rand() % TWOK, rand() % TWOK);
    }

    return points;
}

void printArray(Point* points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        points[i].print();
    }
}

bool myfunction(Point a, Point b) {
    return a.getX() < b.getX();
}

void sortPoints(Point* points, int numPoints) {
    sort(points,points+numPoints + 1, myfunction);
}

void swapPointsDistance(Point &a, Point &b, double &x, double &y) {
    Point c(0,0);
    double z;
    c = Point(a.getX(),a.getY());
    a = Point(b.getX(),b.getY());
    b = Point(c.getX(),c.getY());

    z = x;
    x = y;
    y = z;
}

void sortPointsByDistance(Point* &points, double* &distances, int numPoints) {
    int ok = 1;
    while (ok) {
        ok = 0;
        for (int i = 0; i < numPoints - 1; ++i) {
            if (distances[i] > distances[i + 1]) {
                //csere
                swapPointsDistance(points[i], points[i+1],distances[i],distances[i+1]);
                ok = 1;
            }
        }
    }
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
    Point* farthestPoints = new Point[10];
    double* distances = new double[10];
    Point OO(0,0);
    double d;

    if (numPoints <= 10) {
        for (int i = 0; i < numPoints; ++i) {
            farthestPoints[i] = Point(points[i].getX(),points[i].getY());
            distances[i] = distance(points[i],OO);
        }
        sortPointsByDistance(points,distances,numPoints);
    } else {
        for (int i = 0; i < 10; ++i) {
            farthestPoints[i] = Point(points[i].getX(),points[i].getY());
            distances[i] = distance(points[i],OO);
        }

        sortPointsByDistance(farthestPoints,distances,10);

        for (int i = 10; i < numPoints; ++i) {
            d = distance(points[i],OO);
            int j = 9;
            while (j > 0) {
                if (d > distances[j]) {
                    for (int k = 0; k < j; ++k) {
                        distances[k] = distances[k+1];
                        farthestPoints[k] = Point(farthestPoints[k+1].getX(),farthestPoints[k+1].getY());
                    }
                    distances[j] = d;
                    farthestPoints[j] = Point(points[i].getX(),points[i].getY());
                    j = 0;
                }
                j--;
            }
        }
    }

    return farthestPoints;
}

void deletePoints(Point* points){
    delete []points;
}