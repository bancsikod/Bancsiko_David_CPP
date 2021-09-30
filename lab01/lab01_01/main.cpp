#include <iostream>
using namespace std;

int countBits(int x) {
    int b = 0;
    while(x > 0) {
        b += x & 1;
        x = x >> 1;
    }
    return b;
}

int main() {

    for(int i = 0; i <= 127; ++i) {
        cout << countBits(i) << " ";
    }
    return 0;
}
