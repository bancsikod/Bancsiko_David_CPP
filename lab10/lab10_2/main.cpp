#include <iostream>
#include "Student.h"

int main() {

    Student S(1,"Marko", "Polo");
    S.addGrade("Magyar", 10);
    S.addGrade("Roman", 4.25);
    S.addGrade("Matek", 9.75);
    S.addGrade("Info", 7.6);
    S.computeAverage();

    cout << S << endl;
    cout << S.getGrade("Roman") << endl;
    map<string, double> a = S.getGrades();

    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << i->first << " " << i->second << endl;
    }

    cout << S.getAverage() << endl;
    cout << S.getId() << " " << S.getFirstName() << " " << S.getLastName() << endl;

    return 0;
}
