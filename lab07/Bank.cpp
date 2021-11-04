//
// Created by David on 11/04/2021.
//

#include "Bank.h"
#include <fstream>
#include <sstream>

Bank::Bank(const string &tag)
: name(tag) {

}

int Bank::newCustomer(const string &firstName, const string &lastName) {
    customers.emplace_back(firstName,lastName);
    return customers.back().getId();
}

bool Bank::deleteCustomer(int id) {
    for (auto i = customers.begin(); i != customers.end(); ++i) {
        if (i->getId() == id) {
            customers.erase(i);
            return true;
        }
    }
    return false;
}

Customer &Bank::getCustomer(int id) {
    for (Customer &customer: customers) {
        if (customer.getId() == id) {
            return customer;
        }
    }
    throw runtime_error("Customer not found");
}

void Bank::printCustomers(ostream &os) const {
    os << name << endl;
    for (Customer const &customer: customers) {
        os << '\t' << customer.getId() << " " << customer.getFirstName() << " " << customer.getLastName() << endl;
    }
}

void Bank::printCustomersAndAccounts(ostream &os) const {
    os << name << endl;
    for (Customer const &customer: customers) {
        cout << customer;
    }
}

vector<int> Bank::loadCustomers(const string &filename) {
    ifstream fptr(filename);
    if(!fptr) {
        throw runtime_error("File is empty");
    }

    vector<int> IDs;

    string line;
    while (getline(fptr, line)) {
        istringstream ss(line);
        string s1, s2;
        ss >> s1 >> s2;
        IDs.emplace_back(newCustomer(s1,s2));
    }

    return IDs;
}
