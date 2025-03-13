#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

//Constructor
Roster::Roster() {
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
}
 
// Functions
void Roster::parse(const string &studentData) {
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degreeStr = studentData.substr(lhs, rhs - lhs);
    DegreeProgram degreeProgram;
    
    if (degreeStr == "SECURITY") degreeProgram = SECURITY;
    else if (degreeStr == "NETWORK") degreeProgram = NETWORK;
    else degreeProgram = SOFTWARE;
    
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysToComplete[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
}

void Roster::remove(string studentID) {
    bool found = false;
    for(int i = 0; i <= lastIndex; i++) {
        if(classRosterArray[i]->get_studentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            //Shifting the remaining elements to the left to fill the gap left from deleting
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j+1];
            }
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            break; // Exits the loop
        }
    }
    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
        }
}
    
void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->get_studentID() == studentID) {
            const int *days = classRosterArray[i]->get_daysToComplete();
            float averageDays = (days[0] + days[1] + days[2]) / 3.0;
            cout << "StudentID #" << studentID << ", average days in course: " << averageDays << endl;
            return;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->get_emailAddress();
        if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
            cout << "Invalid email: " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Degree Program: ";
        if(degreeProgram == SECURITY)
            cout << "SECURITY" << endl;
        if(degreeProgram == NETWORK)
            cout << "NETWORK" << endl;
        if(degreeProgram == SOFTWARE)
            cout<< "SOFTWARE" << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->get_degreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
