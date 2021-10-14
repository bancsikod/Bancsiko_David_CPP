//
// Created by David on 10/14/2021.
//

#ifndef LAB04_POINTSET_H
#define LAB04_POINTSET_H

#include "Point.h"
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class PointSet{
    //különböző pontok
    vector<Point> points;
    //különböző pontok száma
    int n;
    //pontok kozotti tavolsagok
    vector<double> distances;
    //segédfüggvény, amely feltölti a distances tömböt
    void computeDistances();
public:
    //konstruktor: előállítja a points tömböt
    //kiszámítja a pontok közötti távolságokat (tavolsagok tömb),
    PointSet( int n = 100 );
    //maximum kiválasztás a tavolsag tömbből
    double maxDistance() const;
    //minimum kiválasztás a tavolsag tömbből
    double minDistance() const;
    //összesen hány távolság értelmezhető n
    //különböző pont között
    int numDistances() const;
    //a pontok tároló kiíratása
    void printPoints() const;
    //a tavolsagok tároló kiíratása
    void printDistances() const;
    //növekvő sorrendbe rendezi a pontokat x koordináta szerint
    void sortPointsX();
    //u. a. y koordináta szerint
    void sortPointsY();
    //a tavolsagok tároló rendezése
    void sortDistances();
    //hány darab különböző távolságot tartalmaz a tavolsagok tömb
    int numDistinctDistances();
};

#endif //LAB04_POINTSET_H
