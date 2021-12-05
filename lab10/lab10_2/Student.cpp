//
// Created by David on 11/28/2021.
//

#include "Student.h"

int Student::getId() const {
    return ID;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

double Student::getAverage() const {
    return average;
}

Student::Student(int id, const string &firstName, const string &lastName)
: ID(id)
, firstName(firstName)
, lastName(lastName)
, average(0){
    grades.clear();
}

void Student::addGrade(const string &examName, double grade) {
    grades.emplace(examName,grade);
}

double Student::getGrade(const string &examName) const {
    auto it = grades.find(examName);
    return it->second;
}

void Student::computeAverage() {
    double sum = 0;
    for (auto & grade : grades) {
        if (grade.second < 5) {
            sum = 0;
            break;
        }
        sum += grade.second;
    }
    average = sum / grades.size();
}

ostream &operator<<(ostream &os, Student &student) {
    os << student.ID << " " << student.firstName << " " << student.lastName << ":\n";
    for (auto & grade : student.grades) {
        os << "\t" << grade.first << " " << grade.second << endl;
    }
    cout << "\tAvg: " << student.average;
    return os;
}
