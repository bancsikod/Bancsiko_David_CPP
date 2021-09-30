#include <iostream>
#include "function.h"
using namespace std;

int main(int argc,char **argv) {
    int n;
    cin >> n;
    double array[100] = {0};

    for(int i = 0; i < n; ++i) {
        array[i] = i;
    }

    cout << mean(array, n);



    return 0;
}
