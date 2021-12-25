//
// Created by David on 12/25/2021.
//

#ifndef LAB12_ITERATOR_H
#define LAB12_ITERATOR_H

#include "OrderedList.h"

template <class T, class LessComp, class Equal>
class Iterator {
    OrderedList<T, LessComp, Equal> &list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    Iterator(OrderedList<T, LessComp, Equal> &list);
    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
Iterator<T, LessComp, Equal>::Iterator(OrderedList<T, LessComp, Equal> &list)
: list(list) {
    act = list.first;
}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    return act != nullptr;
}

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    T d = act->value;
    act = act->next;
    return d;
}


#endif //LAB12_ITERATOR_H
