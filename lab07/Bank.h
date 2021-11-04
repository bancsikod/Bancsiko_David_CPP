//
// Created by David on 11/04/2021.
//
/**Hozzon létre egy bankot.
● Olvassa be a bank ügyfeleit egy customers.txt állományból (minden sor egy ügyfél vezeték
és keresztnevét tartalmazza, a fájl legkevesebb 3 ügyfelet tartalmazzon).
● Írassa ki a bank ügyfeleit.
● Minden beolvasott ügyfélhez rendeljen hozzá legalább két számlát, majd végezzen
műveleteket a számlákkal. Minden műveletet a bank példányon keresztül kell végezni!
● A műveletek után írassa ki az ügyfeleket a számlákkal együtt!
 */

#ifndef LAB07_BANK_H
#define LAB07_BANK_H


#include <string>
#include "Customer.h"
using namespace std;
class Bank {
public:
    Bank(const string&);
//returns the ID of the new Customer
    int newCustomer(const string& firstName, const string& lastName );
    bool deleteCustomer(int id);
    Customer& getCustomer(int id);
//Convenience functions
    void printCustomers(ostream& os=cout) const;
    void printCustomersAndAccounts(ostream& os=cout) const;
//LOAD customers, returns their IDs
    vector<int> loadCustomers(const string& filename);
private:
    vector<Customer> customers;
    string name;
};


#endif //LAB07_BANK_H
