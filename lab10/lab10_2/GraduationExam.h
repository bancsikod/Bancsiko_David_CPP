//
// Created by David on 11/28/2021.
//

#ifndef LAB10_2_GRADUATIONEXAM_H
#define LAB10_2_GRADUATIONEXAM_H

#include <iostream>
#include "Student.h"

using namespace std;

class GraduationExam {
    int year;
    map<int, Student> students;
private:
    void enrollment(string&);
    int numStudents() const;
    void readGradesOfSubject(string&, string&);
    void computeFinalGrades();
    const map<string, double> &getGrades(int) const;
    int numPassed() const;
};


#endif //LAB10_2_GRADUATIONEXAM_H
