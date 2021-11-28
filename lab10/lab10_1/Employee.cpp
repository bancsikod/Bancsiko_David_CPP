//
// Created by David on 11/25/2021.
//

#include "Employee.h"

int Employee::hash{0};

Employee::Employee(string firstName, string lastName, int birth, string job)
: Person(std::move(firstName),std::move(lastName),birth)
, job(std::move(job))
, id(++hash) {

}

void Employee::print(ostream &os) const {
    os << "Employee " << id << " ";
    Person::print(os);
    os << " " << job;
}

const int &Employee::getId() const{
    return id;
}


