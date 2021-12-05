#include <iostream>
#include "index.h"

int main() {
    map<string, set<int>> index = readIndexText("indexfile");
    print(cout,index);



    return 0;
}
