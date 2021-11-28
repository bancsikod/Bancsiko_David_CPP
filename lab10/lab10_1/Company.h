//
// Created by David on 11/28/2021.
//

#ifndef LAB10_1_COMPANY_H
#define LAB10_1_COMPANY_H

#include "Manager.h"

class Company {
    string name;
    vector<Employee*> employees;
public:
    Company(string name);
    const string &getName() const;
    //hire person
    int hireEmployee(Employee *employee);
    //fire employee by id
    void fireEmployee(int id);
    //add to manager
    void addToManager(Manager &man, Employee *emp);
    //remove from manager
    void removeFromManager(Manager&, int);
    //print all
    void printAll(ostream&);
    //print only manager
    void printManagers(ostream&);
};


#endif //LAB10_1_COMPANY_H
