#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Temi,Otunbanjo,Totunba@wgu.edu,31,10,30,45,SOFTWARE"
};

int main () {
    //Course information
    cout << "Course Title: C867 Scripting and Programming - Applications" <<endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 011336027" << endl;
    cout << "Student Name: Temitope Otunbanjo" << endl;
    cout << endl;
    
    Roster classRoster;
    
    //Adding each student to classRoster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }
    
    classRoster.printAll();
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    for (int i = 0; i < 5; i++){
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->get_studentID());
    }
    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster.remove("A3");
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
    
    return 0;
}
 
