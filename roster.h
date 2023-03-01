#pragma once
#include "student.h"
// #include "degree.h"
#include "roster.h"
#include <iostream>
#include <string>
#include <iomanip>

#include <array>
using namespace std;


class Roster {

public:
	/* Default Constructor */
	Roster();  

	/* Deconstructor with print messages to indicate that it is working */
	~Roster();

	/* Reads a string and parses and prepares data for a student object */
	void parse(string row);

	/* Creates a student object with data received from parse() function.
	   Stores student objects in a Roster Array. */
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	/* Removes a student object from Roster Array*/
	void remove(string studentID);

	/* Iterates through roster array calling Students print function to display data on all students 
	   in Roster */
	void printAll();

	/* Adds up days in each course and prints the average */
	void printAverageDaysInCourse(string studentID);

	/* Display Student name and email of any student in roster with an invalid email. Valid emails contain an '@' sign and a '.' and
*  no spaces. */
	void printInvalidEmails();

	/* Prints each student whose degree program matches input paramaters */
	void printByDegreeProgram(DegreeProgram degreeProgram);

private:
	int lastIndex = 0; // Used to keep track of the working size of the array of students
	const static int numStudents = 5; // Initial size of array of students
	Student* classRosterArray[numStudents]; // Array of student objects
	
};