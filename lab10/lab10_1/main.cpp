#include "Manager.h"
#include "Company.h"
#include <typeinfo>

int main() {
    Company bdr("BDR");

    Employee e1("Kasza", "Tibi", 2001, "baros");
    Employee e2("Csergo", "Adam", 2001, "baros");
    Employee e3("Ubi", "Ibi", 2001, "szakacs");
    Employee e4("Szep", "Lilla", 2001, "pincer");
    Employee e5("Ordog", "Maria", 2001, "fo szakacs");
    Employee e6("Horvat", "Janos", 2001, "takarito");
    Employee e7("Arany", "Takony", 1999, "kapus");
    Manager m1("Bator", "Balazs", 2001, Manager::MANAGER_JOB);
    Manager m2("Karcsi", "Julia", 2001);
    Manager m3("Jozsef", "Akos", 2001);

    bdr.hireEmployee(&e1);
    bdr.hireEmployee(&e2);
    bdr.hireEmployee(&e3);
    bdr.hireEmployee(&e4);
    bdr.hireEmployee(&e5);
    bdr.hireEmployee(&e6);
    bdr.hireEmployee(&e7);
    bdr.hireEmployee(&m1);
    bdr.hireEmployee(&m2);
    bdr.hireEmployee(&m3);

    bdr.printAll(cout);

    bdr.addToManager(m1,&e1);
    bdr.addToManager(m2,&e2);
    bdr.addToManager(m1,&e3);
    bdr.addToManager(m3,&e4);
    bdr.addToManager(m2,&e5);
    bdr.addToManager(m3,&e6);
    bdr.addToManager(m1,&e7);

    cout << endl;
    bdr.printManagers(cout);

    bdr.removeFromManager(m1,1);
    bdr.addToManager(m3,&e1);
    cout << endl;
    bdr.printManagers(cout);


    return 0;
}
