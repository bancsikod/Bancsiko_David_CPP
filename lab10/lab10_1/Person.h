//
// Created by David on 11/25/2021.
//

#ifndef LAB10_1_PERSON_H
#define LAB10_1_PERSON_H

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
    int birth;
public:
    Person(string, string, int);
    virtual void print(ostream& os) const;
};

ostream & operator <<(ostream& in, const Person& what);


#endif //LAB10_1_PERSON_H
