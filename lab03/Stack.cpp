//
// Created by David on 10/08/2021.
//

#include "Stack.h"

void Stack::push(int e) {
    obj.insertFirst(e);
}

int Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("Error: is empty");
    }
    return obj.removeFirst();
}

bool Stack::isEmpty() const {
    return obj.empty();
}
