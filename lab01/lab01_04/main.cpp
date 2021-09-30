#include <iostream>
#include "function.h"
using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    double array[n];
    for(int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << stddev(array,n);

    return 0;
}
