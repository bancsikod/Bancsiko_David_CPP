//
// Created by David on 12/02/2021.
//

#include <stdexcept>
#include "index.h"
#include <algorithm>



map<string, set<int>> readIndexText(const string &fname) {
    ifstream fptr(fname);
    if (fptr == nullptr) {
        throw runtime_error("File is empty");
    }

    map<string, set<int>> index;
    set<int> s;

    string line;

    while (getline(fptr,line)) {
        if (line.length() == 0) {
            break;
        }
        transform(line.begin(), line.end(), line.begin(), ::toupper);
        index.emplace(line, s);
    }

    int rowCount = 1;
    while (getline(fptr, line)) {
        replace_if(line.begin(), line.end(), [](char c) { return !isalpha(c); }, ' ');
        transform(line.begin(), line.end(), line.begin(), ::toupper);

        istringstream ss(line);
        string word;

        while (ss >> word) {

            for (auto &string: index) {
                if (string.first == word) {
                    index[string.first].insert(rowCount);
                }
            }
        }
        rowCount++;
    }

    fptr.close();
    return index;
}

void print(ostream &os, map<string, set<int>> &index) {
    for (auto i = index.begin(); i != index.end() ; ++i) {
        os << i->first << " ";

        set<int> st = i->second;

        for (auto &j : st) {
            os << " " << j;
        }
        os << endl;
    }
}
