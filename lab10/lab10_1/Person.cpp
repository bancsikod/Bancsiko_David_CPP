//
// Created by David on 11/25/2021.
//

#include "Person.h"

Person::Person(string firstName, string lastName, int birth)
: firstName(std::move(firstName))
, lastName(std::move(lastName))
, birth(birth) {

}

void Person::print(ostream & os) const {
    os << firstName << " " << lastName;
}

ostream & operator <<(ostream& os, const Person& what) {
    what.print(os);
    return os;
}