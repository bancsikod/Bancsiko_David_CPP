#include "Customer.h"
#include "Account.h"
#include "Bank.h"

int main() {
    cout << "--------------------------------------------" << endl;
    cout << "<<<<<  1. Feladat - Account osztaly  >>>>>" << endl;
    cout << "--------------------------------------------" << endl;
    Account Kevin(0);
    Kevin.print(cout);
    Kevin.deposit(1000);
    Kevin.print(cout);
    Kevin.withdraw(500);
    cout << Kevin;
    try {
        Kevin.withdraw(1000);
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    Kevin.print(cout);
    Account David(0);
    David.print(cout);
    cout << David;

    cout << endl;

    cout << "--------------------------------------------" << endl;
    cout << "<<<<<  2. Feladat - Customer osztaly  >>>>>" << endl;
    cout << "--------------------------------------------" << endl;
    Customer Orsi("Habibi", "Orsolya");
    Orsi.newAccount(0);
    Orsi.newAccount(1000);
    cout << Orsi;

    Orsi.deleteAccount(3);
    cout << Orsi;
    Orsi.newAccount(1000);
    cout << Orsi[1];
    try {
        cout << Orsi.getAccount(4);
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "<<<<<  3. Feladat - Bank osztaly  >>>>>" << endl;
    cout << "--------------------------------------------" << endl;
    Bank bdr("BDR");
    vector<int> customerIds = bdr.loadCustomers("customers.txt");
    bdr.printCustomers(cout);
    for (int & customerId : customerIds) {
        bdr.getCustomer(customerId).newAccount(500);
        bdr.getCustomer(customerId).newAccount(1000);
    }

    bdr.getCustomer(2).getAccount(6).deposit(650);
    bdr.getCustomer(2).getAccount(7).deposit(880);
    try {
        bdr.getCustomer(2).getAccount(7).withdraw(1280);
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    bdr.getCustomer(3).getAccount(8).deposit(650);
    try {
        bdr.getCustomer(3).getAccount(9).withdraw(650);
        bdr.getCustomer(3).getAccount(8).withdraw(650);
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    bdr.getCustomer(4).getAccount(10).deposit(650);
    try {
        bdr.getCustomer(4).getAccount(11).withdraw(650);
        bdr.getCustomer(4).getAccount(10).withdraw(2000);
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    bdr.printCustomersAndAccounts(cout);

    return 0;
}
