#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
    double sum = 0;
    for (int i = 1; i < argc; ++i) {
        istringstream ss(argv[i]);
        double d;
        if(ss >> d){
            sum += d;
        }
    }
    cout << sum;
    return 0;
}
