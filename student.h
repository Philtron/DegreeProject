#pragma once
#include "degree.h"
#include <string>
#include <iostream>
#include <iomanip>
using std::string;
using std::cout;
using std::endl;

class Student {
public:

	const static int daysInDegreesize = 3; 	

	/* Setters/Mutators */
	void setStudentID(string studentID);
	void setStudentFirstName(string firstName);
	void setStudentLastName(string lastName);
	void setStudentEmail(string studentEmail);
	void setStudentAge(int studentAge);
	void setNumDaysDegree(int numDaysDegree[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	
	/* Getters/Accessors */
	string getStudentID();
	string getStudentFirstName();
	string getStudentLastName();
	string getStudentEmail();
	int getStudentAge();
	int* getNumDaysDegree();
	DegreeProgram getDegreeProgram();

	static void printHeader(); // Prints header above printed data
	void print(); // Prints "this" students information
	
	Student(); // Default Constructor
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, 
		unsigned int studentAge, int numDaysInDegree[], DegreeProgram degree); // Full Constructor
	~Student(); // Destructor

private:
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	unsigned int studentAge;
	int numDaysInDegree[daysInDegreesize];
	DegreeProgram degreeProgram;

};