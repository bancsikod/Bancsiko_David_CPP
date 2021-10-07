//
// Created by David on 10/07/2021.
//

#include "List.h"

List::List() {
    this->first = nullptr;
}

List::~List() {
    while (first != nullptr) {
        Node* temp = first;
        first = temp->next;
        delete temp;
    }
}

bool List::exists(int d) const {
    for(Node* p = first; p; p = p->next) {
        if (p->value == d) {
            return true;
        }
    }
    return false;
//    while (first != nullptr) {
//        if (first->value == d) {
//            return true;
//        }
//        first = first->next; - ez hibas sor
//    }
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    if (first == nullptr) {
        return true;
    }
    return false;
}

void List::insertFirst(int d) {
    first = new Node(d,first);
    nodeCounter++;
}

int List::removeFirst() {
    if (empty()) {
        return -1;
//        throw runtime_exception("hiba");
    }
    Node* temp = first;
    first = temp->next;
    nodeCounter--;
    return 1;
}

void List::remove(int d, DeleteFlag df) {
    for(Node* p = first; p; p = p->next) {
        if (df == DeleteFlag::EQUAL && d == p->value) {

        }
    }
//    if (df == DeleteFlag::EQUAL) {
//        Node* i = first;
//        Node* j = nullptr;
//        while (i != nullptr) {
//            if (d == i->value) {
//
//            }
//            j = i;
//            i = i->next;
//        }
//    }
}

void List::print() const {
    for (Node* i = first; i; i = i->next) {
        cout << i->value << " ";
    }
}