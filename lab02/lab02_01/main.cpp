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

//    delete pp1;
//    delete pp2;

    testIsSquare("points.txt");

    int N;
    cout << "N= ";
    cin >> N;


    Point* points_a = new Point[N];
    points_a = createArray(N);



    printArray(points_a,N);

    sortPoints(points_a,N);

    cout << endl << "sorted:" << endl;
    printArray(points_a,N);

//    Point OO(0,0);
//    cout << "\n" << OO.getX() << " " << OO.getY() << " \n";
//    cout << "\n d = " << distance(*pp1,*pp2) << endl;
//
//    double d = 0;
//    double dd = 0;
//
//
//    d = distance(p1,p2);
//    dd = distance(p2,p1);
//    p1.print();
//    p2.print();
//    printf("%.2f", d);
//    cout << "\nd = " << d << "\ndd = " << dd;
//
//    swapPointsDistance(p1,p2,d,dd);
//
//    p1.print();
//    p2.print();
//    cout << "\nd = " << d << "\ndd = " << dd;

    Point* farthest_points = new Point[10];
    farthest_points = farthestPointsFromOrigin(points_a,N);

    cout << "\nfarthest points: \n";
    printArray(farthest_points,10);

    deletePoints(points_a);

    return 0;
}
