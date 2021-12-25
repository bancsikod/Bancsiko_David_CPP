#include <iostream>
#include "Student.h"
#include "GraduationExam.h"
#include "IGraduation.h"
#include "GraduationInfo.h"

string subjects[] {"Romanian", "Hungarian", "Math"};

int main() {

    GraduationExam exam;
    exam.enrollment("names.txt");
    cout<<exam.numStudents()<<endl;
    exam.readGradesOfSubject(subjects[0], "romanian.txt");
    exam.readGradesOfSubject(subjects[1], "hungarian.txt");
    exam.readGradesOfSubject(subjects[2], "maths.txt");
    exam.computeFinalGrades();

    IGraduation * graduation = new GraduationInfo( exam );
    cout<<"Graduation Information"<<endl;
    cout<<"Number of enrolled students: "<<graduation->getNumEnrolled()<<endl;
    cout<<"Number of passed students: "<<graduation->getNumPassed()<<endl;
    //cout<<"Number of failed students: "<<graduation->getNumFailed()<<endl;
    int ID;
    for( ;; ){
        cout<<"Enter an ID <0 for termination>: ";
        cin>>ID;
        if( ID == 0 ){
            break;
        }
        cout<<"Information:"<<endl;
        try{
            const Student& student = graduation->getStudent( ID );
            cout<<student<<endl;
        }catch( domain_error& e){
            cout<<e.what()<<endl;
        }
    }
    graduation->printResults(cout);
    delete graduation;
    return 0;


    //    Student S(1,"Marko", "Polo");
//    S.addGrade("Magyar", 10);
//    S.addGrade("Roman", 4.25);
//    S.addGrade("Matek", 9.75);
//    S.addGrade("Info", 7.6);
//    S.computeAverage();
//
//    cout << S << endl;
//    cout << S.getGrade("Roman") << endl;
//    map<string, double> a = S.getGrades();
//
//    for (auto i = a.begin(); i != a.end(); ++i) {
//        cout << i->first << " " << i->second << endl;
//    }
//
//    cout << S.getAverage() << endl;
//    cout << S.getId() << " " << S.getFirstName() << " " << S.getLastName() << endl;

}
