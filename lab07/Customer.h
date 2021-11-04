//
// Created by David on 11/04/2021.
//
/**
 * Adott egy Customer.h állomány, amely egy banki ügyfelet deklarál.
● Az id mező generálása az Account osztályhoz hasonlóan történik a counter statikus
adattag segítségével.
● Az ügyfél számláit az accounts dinamikus tömbben tároljuk.
● A getAccount(id) függvény visszatéríti a megadott azonosítójú számlát.
________________________________________________________________________________
● Az index operátor a megadott sorszámú bankszámlát téríti vissza.
*Implementálja a Customer osztályt.
● Hozzon létre egy Customer példányt.
● Nyisson két bankszámlát a megadott ügyfélnek, az elsőnek legyen 0 kezdőegyenlege, a
másodiknak pedig 1000 RON.
● Írassa ki az ügyfelet az inserter operátor segítségével. A kiíratás legyen szépen formázott.

 */

#ifndef LAB07_CUSTOMER_H
#define LAB07_CUSTOMER_H

#include "Account.h"
#include <string>
#include <vector>

class Customer {
private:
    int id; //generated field
    string firstName;
    string lastName;
    vector<Account> accounts;
    static int counter;
public:
    Customer(const string& firstName, const string& lastName);
    const string &getFirstName() const;
    void setFirstName(const string &firstName);
    const string &getLastName() const;
    void setLastName(const string &lastName);
    int getId() const{ return id;}
    Account& getAccount(int id);
//returns the ID of the created account
    int newAccount(double balance);
    bool deleteAccount(int id);
    int getNumAccounts() const;
    void print(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Customer& customer);
    Account& operator[](int index);
    const Account& operator[](int index) const;
};


#endif //LAB07_CUSTOMER_H
