//
// Created by David on 12/09/2021.
//

#include "GraduationInfo.h"
#include "Student.h"
#include <iostream>

int GraduationInfo::getNumEnrolled() const {
    return 0;
}

int GraduationInfo::getNumPassed() const {
    return 0;
}

GraduationInfo::GraduationInfo(GraduationExam &exam)
: graduationExam(exam){

}

const Student &GraduationInfo::getStudent(int id) const {
    return graduationExam.students.at(id);
}

const string &GraduationInfo::getLastName(int id) const {
    return getStudent(id).getLastName();
}

const string &GraduationInfo::getFirstName(int id) const {
    return getStudent(id).getFirstName();
}

void GraduationInfo::printResults(ostream &os) const {
    for (const auto &it : graduationExam.students) {
        os << it.second << endl;
    }
}

void GraduationInfo::printPassed(ostream &os) const {
    for (const auto &it : graduationExam.students) {
        if (it.second.getAverage() >= 6)
            os << it.second << endl;
    }
}

void GraduationInfo::printFailed(ostream &os) const {
    for (const auto &it : graduationExam.students) {
        if (it.second.getAverage() < 6)
            os << it.second << endl;
    }
}
