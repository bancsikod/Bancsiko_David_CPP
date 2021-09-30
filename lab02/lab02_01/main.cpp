#include "function.h"

int main() {
    Point p1(2,3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
    Point p2(100,200);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
    Point * pp1 = new Point(300,400);
    Point * pp2 = new Point(500,1000);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;

    p1.print();

    cout << endl << "Tav= " << distance(*pp1,*pp2) << endl;

    cout << endl << "negyzete? = " << isSquare(p1,p2,*pp1,*pp2) << endl;

    delete pp1;
    delete pp2;

    return 0;
}
