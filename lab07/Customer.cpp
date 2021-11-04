//
// Created by David on 11/04/2021.
//

#include <algorithm>
#include "Customer.h"

int Customer::counter{0};

Customer::Customer(const string &firstName, const string &lastName)
: firstName(firstName)
, lastName(lastName)
, id(++counter) {

}

const string &Customer::getFirstName() const {
    return firstName;
}

void Customer::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

void Customer::setLastName(const string &lastName) {
    this->lastName = lastName;
}

Account &Customer::getAccount(int id) {
    for (Account &acc: accounts) {
        if (acc.getId() == id) {
            return acc;
        }
    }
    throw runtime_error("Account not found");
}

int Customer::newAccount(double balance) {
    accounts.emplace_back(balance);
    return accounts.back().getId();
}

bool Customer::deleteAccount(int id) {
    for (auto i = accounts.begin(); i != accounts.end() ; ++i) {
        if (i->getId() == id) {
            accounts.erase(i);
            return true;
        }
    }
    return false;
}

int Customer::getNumAccounts() const {
    return accounts.size();
}

void Customer::print(ostream &os) const {
    os << id << " " << firstName << " " << lastName << endl;
    for (Account const &acc: accounts) {
        cout << '\t' <<acc;
    }
}

ostream &operator<<(ostream &os, const Customer &customer) {
    customer.print(os);
    return os;
}

Account &Customer::operator[](int index) {
    return accounts[index];
}

const Account &Customer::operator[](int index) const {
    return accounts[index];
}



