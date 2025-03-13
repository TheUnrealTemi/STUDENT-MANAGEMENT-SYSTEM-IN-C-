#ifndef student_h
#define student_h

#include <string>
#include "degree.h"
using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;
    
public:
    //constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, const int daysToComplete[], DegreeProgram degreeProgram);
    Student();

    //accessors
    string get_studentID() {return studentID;}
    string get_firstName() {return firstName;}
    string get_lastName() {return lastName;}
    string get_emailAddress() {return emailAddress;}
    int get_age() {return age;}
    const int *get_daysToComplete() {return daysToComplete;}
    DegreeProgram get_degreeProgram() {return degreeProgram;}
    
    //mutator
    void set_studentID(string ID) {studentID = ID;}
    void set_firstName(string first) {firstName = first;}
    void set_lastName(string last) {lastName = last;}
    void set_emailAddress(string email) {emailAddress = email;}
    void set_age(int a) {age = a;}
    void set_daysToComplete(const int days[]);
    void set_degreeProgram(DegreeProgram degree) {degreeProgram = degree;}

    //function
    void print() const;
    
};

#endif /* student_h */
 
