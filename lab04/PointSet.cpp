//
// Created by David on 10/14/2021.
//

#include "PointSet.h"

PointSet::PointSet( int n) : n{n} {
//    this->n = n;
    points.reserve(n);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        points.emplace_back(Point(rand() % M, rand() % M));
    }
    this->computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            distances.emplace_back(points[i].distanceTo(points[j]));
        }
    }
}

//for(int i = 0; i < a.size(); ++i) {
//    cout << a[i];
//}
//for(auto it = a.begin(); it != a.end(); it++) {
//    cout << *it;
//}

//minelement 2 parameter hol kezdodik, hol vegzodik, * mert pointert terit vissza
double PointSet::minDistance() const {
    return *min_element(distances.begin(),distances.end());
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(),distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

//sort(a.begin(),a.end()),[](const Point &a, const Point &b) { return a.getX() < b.getX(); });
void PointSet::printPoints() const {
    for (auto it = points.begin(); it != points.end(); it++) {
        cout << it->getX() << " " << it->getY() << " ";
    }
}

void PointSet::printDistances() const {
    for (auto it = distances.begin(); it != distances.end(); it++) {
        cout << *it << " ";
    }
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(),distances.end());
}

int PointSet::numDistinctDistances() {
    vector<double> distances = this->distances;
    sortDistances();
    auto it = unique(distances.begin(),distances.end());
    return it - distances.begin();
}
