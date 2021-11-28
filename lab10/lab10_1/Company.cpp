//
// Created by David on 11/28/2021.
//

#include "Company.h"
#include <utility>
#include <typeinfo>

Company::Company(string name)
: name(std::move(name)) {

}

const string &Company::getName() const {
    return name;
}

int Company::hireEmployee(Employee* employee) {
    employees.emplace_back(employee);
    return employees.back()->getId();
}

void Company::fireEmployee(int id) {
    auto it = remove_if(employees.begin(), employees.end(), [id](Employee* emp) {
        return emp->getId() == id;
    });
    employees.erase(it,employees.end());
}

void Company::addToManager(Manager &man, Employee *emp) {
    man.addEmployee(emp);
}

void Company::removeFromManager(Manager &man, int id) {
    man.deleteByID(id);
}

void Company::printAll(ostream &os) {
    os << "Company: " << name << endl;
    for (Employee *employee: employees) {
        os << *employee << endl;
    }
}

void Company::printManagers(ostream& os) {
    os << "Company: " << name << endl;
    for (Employee *employee: employees) {
        if (dynamic_cast<Manager*>(employee)) {
            os << *employee << endl;
        }
    }
}
