#include <iostream>
#include "Student.h"

int main() {

    Student S(1,"Molnar", "Orsi");
    S.addGrade("Magyar", 10);
    S.addGrade("Roman", 4.25);
    S.addGrade("Matek", 9.75);
    S.addGrade("Info", 7.6);
    S.computeAverage();

    cout << S;


    return 0;
}
