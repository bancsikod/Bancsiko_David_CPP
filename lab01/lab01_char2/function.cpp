//
// Created by David on 09/29/2021.
//

#include "function.h"

int countWords(string text) {
    auto counter = 0;
    string temp;
    istringstream iss(text);
    cout << "{ ";
    while (iss >> temp) {
        cout <<counter << ' ' << temp << ' ';
        counter++;
    }
    cout << " }";

    return counter;
}
