//
// Created by David on 12/09/2021.
//

#ifndef LAB10_2_GRADUATIONINFO_H
#define LAB10_2_GRADUATIONINFO_H

#include "IGraduation.h"
#include "GraduationExam.h"

class GraduationInfo : public IGraduation {
    GraduationExam &graduationExam;
public:
    GraduationInfo(GraduationExam&);
    virtual int getNumEnrolled() const override;
    virtual int getNumPassed() const override;
    virtual const Student &getStudent(int id) const override;

    const string &getLastName(int id) const override;

    const string &getFirstName(int id) const override;

    void printResults(ostream &os) const override;

    void printPassed(ostream &os) const override;

    void printFailed(ostream &os) const override;
};


#endif //LAB10_2_GRADUATIONINFO_H
