//
// Created by David on 11/01/2021.
//

#ifndef LAB07_ACCOUNT_H
#define LAB07_ACCOUNT_H

#include <iostream>
#include <stdexcept>

using namespace std;

class Account {
public:
    Account(double balance=0);
    void deposit( double amount);
    bool withdraw(double amount);
    int getId() const;
    double getBalance() const;
    void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Account& account);
private:
    static int counter;
    int id; //generated field
    double balance;
};

#endif //LAB07_ACCOUNT_H
