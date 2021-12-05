//
// Created by David on 11/28/2021.
//

#include "GraduationExam.h"
#include <fstream>
#include <sstream>

// A names.txt fájlban lévő hallgatókat beiratkoztatni az érettségire
void GraduationExam::enrollment(const string &fileName) {
    ifstream fptr(fileName);
    if(!fptr) {
        throw runtime_error("File is empty");
    }

    string line;
    int i = 0;
    while (getline(fptr, line)) {
        istringstream ss(line);
        int id;
        string fn, ls;
        ss >> id >> fn >> ls;
        students.emplace(id,Student(id,fn,ls));
    }

    fptr.close();
}

int GraduationExam::numStudents() const {
    return students.size();
}

// Valamely tantárgy jegyeit tartalmazó fájl beolvasása és a jegyek
// elhelyezése a megfelelő diákhoz
void GraduationExam::readGradesOfSubject(const string &subject, const string &filename) {

}

// Kiszámítja az érettségi átlagát minden diáknak
void GraduationExam::computeFinalGrades() {

}

// Visszatéríti adott azonosítójú diák jegyeit tantárgyakkal együtt
const map<string, double> &GraduationExam::getGrades(int studentID) const {

}

// Sikeresen érettségizők száma
int GraduationExam::numPassed() const {
    return 0;
}
