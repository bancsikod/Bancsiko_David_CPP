//
// Created by David on 12/16/2021.
//

#ifndef LAB12_ORDEREDLIST_H
#define LAB12_ORDEREDLIST_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <class T, class LessComp = less<T>, class Equal = equal_to<T>>
        class Iterator;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList {
    friend class Iterator<T, LessComp, Equal>;
    int numElements{0};
    struct Node {
        T value;
        Node* next;
        Node(const T& v, Node* n) : value(v), next(n) {
        }
    };
    Node* first;
public:
    OrderedList();
    ~OrderedList();
    bool isEmpty();
    void insert(const T& d);
    void remove(const T& d);
    int size() const;
    bool find(T& d) const;
    void listItems(ostream &os);
};

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::OrderedList()
: first(nullptr) {

}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    while (first != nullptr) {
        Node *tmp = first;
        first = tmp->next;
        delete tmp;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    if (first != nullptr) {
        return false;
    }
    return true;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T &d) {
    LessComp cmp;

    Node *prev = nullptr;
    for (Node* p = first; p != nullptr; p = p->next) {
        if (!cmp(p->value, d)) {
            break;
        }
        prev = p;
    }
    if (prev == nullptr) {
        first = new Node(d,first);
    } else {
        prev->next = new Node(d, prev->next);
    }
    numElements++;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T &d) {
    Equal eq;
    LessComp cmp;

    Node *prev = nullptr;
    for (Node *p = first; p != nullptr; p = p->next) {
        if (cmp(p->value, d)) {
            return;
        }
        if (eq(p->value, d)) {
            if (prev == nullptr) {
                first = first->next;
            } else {
                prev->next = p->next;
            }
            delete(p);
            continue;
        }
        prev = p;
    }

    numElements--;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() const {
    return numElements;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(T &d) const {
    Equal eq;

    for (Node *p = first; p != nullptr; p = p->next) {
        if (eq(p->value, d)) {
            return true;
        }
    }
    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &os) {
    for (Node *p = first; p != nullptr; p = p->next) {
        os << p->value << " ";
    }
}


#endif //LAB12_ORDEREDLIST_H
