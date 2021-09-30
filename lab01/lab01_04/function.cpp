//
// Created by David on 09/23/2021.
//

#include "function.h"

double mean(double array[], int numElements) {
    if (numElements == 0) return NAN;
    double sum = 0;
    int i = 0;
    for (i = 0; i < numElements; ++i) {
        sum += array[i];
    }
    return (double ) sum / numElements;
}

double stddev(double array[], int numElements) {
    double sum = 0;
    double m = 0;
    m = mean(array,numElements);

    for (int i = 0; i < numElements; ++i) {
        int element = array[i] - m;
        sum += (element * element);
    }
    return sqrt(sum/numElements);
}