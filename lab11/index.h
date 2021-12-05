//
// Created by David on 12/02/2021.
//

#ifndef LAB11_INDEX_H
#define LAB11_INDEX_H

#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

map<string, set<int>> readIndexText(const string &fname);
void print(ostream &os, map<string, set<int>> &);

#endif //LAB11_INDEX_H
