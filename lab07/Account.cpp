//
// Created by David on 11/01/2021.
//


#include "Account.h"

int Account::counter{0};

Account::Account(double balance)
: balance(balance)
, id(++counter) {
    //counter++;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (balance < amount) {
        //return false;
        throw runtime_error("Error: u have insufficient funds");
    }
    balance -= amount;
    return true;
}

int Account::getId() const {
    return id;
}

double Account::getBalance() const {
    return balance;
}

void Account::print(ostream &os) const {
    os << "{ ID: " << id << "; Balance: " << balance << " }" << endl;
}

ostream &operator<<(ostream &os, const Account &account) {
    account.print(os);
    return os;
}




