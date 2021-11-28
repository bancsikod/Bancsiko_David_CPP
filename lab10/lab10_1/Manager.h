//
// Created by David on 11/25/2021.
//

#ifndef LAB10_1_MANAGER_H
#define LAB10_1_MANAGER_H

#include "Person.h"
#include "Employee.h"
#include <vector>
#include <numeric>



class Manager : public Employee{
    vector<Employee*> employees;

public:
    static const string MANAGER_JOB;

    Manager(string lastName, string firstName, int birth, string job = MANAGER_JOB);
    void addEmployee(Employee* emp);
    void deleteEmployee(Employee* emp);
    void deleteByID(int ID);
    int numEmployees( ) const;
    virtual void print(ostream& os) const;
};




#endif //LAB10_1_MANAGER_H
