//
// Created by David on 11/28/2021.
//

#ifndef LAB10_2_GRADUATIONEXAM_H
#define LAB10_2_GRADUATIONEXAM_H

#include <iostream>
#include "Student.h"

using namespace std;

class GraduationInfo;
class GraduationExam {
    int year;
    map<int, Student> students;
    friend class GraduationInfo;
public:
    void enrollment(const string&);
    int numStudents() const;
    void readGradesOfSubject(const string&, const string&);
    void computeFinalGrades();
    const map<string, double> &getGrades(int) const;
    int numPassed() const;
    void print();
};


#endif //LAB10_2_GRADUATIONEXAM_H
