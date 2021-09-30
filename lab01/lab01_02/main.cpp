#include <iostream>
using namespace std;

bool setBit(int& number, int order) {
    if(order > 31 || order < 0) return false;
    number = number | (1<<order);
    return true;
}


int main() {
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }

    return 0;
}
