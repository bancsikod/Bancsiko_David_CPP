//
// Created by David on 12/09/2021.
//

#ifndef LAB10_2_IGRADUATION_H
#define LAB10_2_IGRADUATION_H

#include "Student.h"

class IGraduation {

public:
    virtual int getNumEnrolled() const = 0;
    virtual int getNumPassed() const = 0;
    virtual const Student &getStudent(int id) const = 0;
    virtual const string &getLastName(int id) const = 0;
    virtual const string &getFirstName(int id) const = 0;
    virtual void printResults(ostream& os) const = 0;
    virtual void printPassed(ostream& os) const = 0;
    virtual void printFailed(ostream& os) const = 0;
};


#endif //LAB10_2_IGRADUATION_H
