#include <iostream>
#include "student.h"
using namespace std;

//Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, const int daysToComplete[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for(int i = 0; i < 3; i++) {this->daysToComplete[i] = daysToComplete[i];}
    this->degreeProgram = degreeProgram;
}

//mutator
void Student::set_daysToComplete( const int days[]) {
    for(int i = 0; i < 3; i++) {
        daysToComplete[i] = days[i];
    }
}

//Function
void Student::print() const {
    cout << "Student ID: " <<studentID << "\t";
    cout << "First Name: " <<firstName << "\t";
    cout << "Last Name: " <<lastName << "\t";
    cout << "Email: " <<emailAddress << "\t";
    cout << "Age: " <<age << "\t";
    cout << "Days in Course: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" <<"\t";
    cout << "Degree Program: ";
        if(degreeProgram == SECURITY)
            cout << "SECURITY" << endl;
        if(degreeProgram == NETWORK)
            cout << "NETWORK" << endl;
        if(degreeProgram == SOFTWARE)
            cout<< "SOFTWARE" << endl;

}
