//
// Created by David on 11/25/2021.
//

#include "Manager.h"
#include "Employee.h"

const string Manager::MANAGER_JOB = "manager";

Manager::Manager(string lastName, string firstName, int birth, string job)
: Employee(std::move(lastName), std::move(firstName), birth, std::move(job)) {

}

void Manager::print(ostream &os) const {
    cout << "Manager " << id << " ";
    Person::print(os);
    if (!employees.empty()) {
        os << " Dependants:" << endl;
    }
    for(Employee *emp: employees) {
        os << "\t" << *emp << endl;
    }
}

void Manager::addEmployee(Employee *emp) {
    employees.push_back(emp);
}

///void Manager::deleteEmployee(Employee *emp) {
////    erase_if(employees, [emp](Employee *employee) {
////        return emp == employee;
////    });
///}

void Manager::deleteEmployee(Employee *emp) {
    auto it = remove_if(employees.begin(), employees.end(), [emp](Employee *employee) {
        return emp == employee;
    });
    employees.erase(it,employees.end());
}

int Manager::numEmployees() const {
    return employees.size();
}

void Manager::deleteByID(int ID) {
    auto it = remove_if(employees.begin(), employees.end(), [ID](Employee* emp) {
        return emp->getId() == ID;
    });
    employees.erase(it,employees.end());
}
//
//if (dynamic_cast<Manager*>(aPtr) != nullptr) {
//// manager
//} else {
//// nem manager
//}