//
// Created by David on 10/08/2021.
//

#ifndef LAB03_STACK_H
#define LAB03_STACK_H

#include "List.h"

class Stack : public List {
    List obj;
public:

    void push(int e);
    int pop();
    bool isEmpty() const;
};


#endif //LAB03_STACK_H
