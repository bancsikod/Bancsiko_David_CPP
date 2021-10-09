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
        throw runtime_error("hiba: ures list");
    }
    Node* temp = first;
    first = temp->next;
    nodeCounter--;
    return temp->value;
}

void List::remove(int d, DeleteFlag df) {
    if (df != DeleteFlag::EQUAL && df != DeleteFlag::GREATER && df != DeleteFlag::LESS) {
        return;
    }

    if ((df == DeleteFlag::LESS && first->value < d) || (df == DeleteFlag::EQUAL && first->value == d) || (df == DeleteFlag::GREATER && first->value > d)) {
        first = first->next;
        nodeCounter--;
        return;
    }

    Node *temp1 = first, *temp2 = nullptr;

    switch (df) {
        case DeleteFlag::LESS:
            while (temp1 && temp1->value >= d) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            break;
        case DeleteFlag::GREATER:
            while (temp1 && temp1->value <= d) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            break;
        case DeleteFlag::EQUAL:
            while (temp1 && temp1->value != d) {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            break;
    }

    if (temp2 && temp1) {
        temp2->next = temp1->next;
        nodeCounter--;
    }

    delete temp1;
    delete temp2;
}

void List::print() const {
    for (Node* i = first; i; i = i->next) {
        cout << i->value << " ";
    }
}