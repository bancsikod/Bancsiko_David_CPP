//
// Created by David on 09/23/2021.
//

#include "function.h"

pair<double, double> max2(double array[], int numElements) {
    pair<double, double> minmnax;
    if (numElements <= 0) {
        return minmnax;
    }
    minmnax.first = array[0];
    minmnax.second = array[0];
    for (int i = 1; i < numElements; ++i) {
        if (array[i] > minmnax.first) {
            minmnax.second = minmnax.first;
            minmnax.first = array[i];
        }
    }

    return minmnax;
}