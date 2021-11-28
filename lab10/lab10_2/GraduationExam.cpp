//
// Created by David on 11/28/2021.
//

#include "GraduationExam.h"
#include <fstream>
#include <sstream>

void GraduationExam::enrollment(string &fileName) {
    ifstream fptr(fileName);
    if(!fptr) {
        throw runtime_error("File is empty");
    }

    string line;
    while (getline(fptr, line)) {
        istringstream ss(line);
        int id;
        string fn, ls;
        ss >> id >> fn >> ls;

    }

    fptr.close();
}
