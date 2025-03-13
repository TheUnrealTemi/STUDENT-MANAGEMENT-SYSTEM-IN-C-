#ifndef roster_h
#define roster_h

#include "student.h"
#include "degree.h"

class Roster {
public:
    Student *classRosterArray[5];
    int lastIndex = -1;
    
    //Constructor
    Roster();
    
    //Destructor
    ~Roster();
    
    //Functions
    void parse(const string &studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
};

#endif /* roster_h */
