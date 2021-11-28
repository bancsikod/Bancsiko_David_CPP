//
// Created by David on 11/25/2021.
//

#ifndef LAB10_1_EMPLOYEE_H
#define LAB10_1_EMPLOYEE_H

#include "Person.h"

class Employee : public Person{
    static int hash;
protected:
    int id;
    string job;
public:
    Employee(string, string, int, string);
    virtual void print(ostream& os) const;
    const int &getId() const;
};


#endif //LAB10_1_EMPLOYEE_H
