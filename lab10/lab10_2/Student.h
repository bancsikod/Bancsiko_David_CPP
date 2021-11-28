//
// Created by David on 11/28/2021.
//

#ifndef LAB10_2_STUDENT_H
#define LAB10_2_STUDENT_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Student {
    int ID;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average;
public:
    Student(int, const string&, const string&);
    int getId() const;
    const string &getFirstName() const;
    const string &getLastName() const;
    const map<string, double> &getGrades() const;
    double getAverage() const;
    void addGrade(const string&, double);
    double getGrade(string&) const;
    void computeAverage();

    friend ostream& operator<<(ostream&, Student&);
};


#endif //LAB10_2_STUDENT_H
