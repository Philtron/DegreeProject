#include "student.h"



// Default Constructor 
Student::Student() { 
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	for (int i = 0; i < daysInDegreesize; i++) {
		this->numDaysInDegree[i] = 0;
	}
	this->degreeProgram = DegreeProgram::UNDECLARED;
	this->studentAge = 18;
	this->studentEmail = "";
}
// Full Constructor
Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail, unsigned int studentAge, int numDaysInDegree[], DegreeProgram degree ) {
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	for (int i = 0; i < daysInDegreesize; i++) {
		this->numDaysInDegree[i] = numDaysInDegree[i];
	}
	this->degreeProgram = degree;
	this->studentAge = studentAge;
	this->studentEmail = studentEmail;
}
// Destructor
Student::~Student() { 
	// Roster destructor will Destroy each object.
} 

// Setters/Mutators
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setStudentFirstName(string firstName) {
	this->studentFirstName = firstName;
}
void Student::setStudentLastName(string lastName) {
	this->studentLastName = lastName;
}
void Student::setStudentEmail(string studentEmail) {
	this->studentEmail = studentEmail;
}
void Student::setStudentAge(int studentAge) {
	this->studentAge = studentAge;
}
void Student::setNumDaysDegree(int numDaysDegree[]) {
	for (int i = 0; i < daysInDegreesize; i++) {
		this->numDaysInDegree[i] = numDaysDegree[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// Getters/Accessors 
string Student::getStudentID() {
	return this->studentID;
}
string Student::getStudentFirstName() {
	return this->studentFirstName;
}
string Student::getStudentLastName() {
	return this->studentLastName;
}
string Student::getStudentEmail() {
	return this->studentEmail;
}
int Student::getStudentAge() {
	return this->studentAge;
}
int* Student::getNumDaysDegree() {
	return this->numDaysInDegree;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

/*Prints a header which displays output format for print functions */
void Student::printHeader() {
	cout << "Output format: ID | First Name | Last Name | Age | Number of Days in Degree | Degree Program" << endl << endl;             
} 

/* Displays general information for a student object */
void Student::print() {
	cout << this->studentID; 
	cout << "\t First Name: " << this->studentFirstName; 
	cout << "\t Last Name: " << this->studentLastName; 
	cout << "\t Age: " << this->studentAge; 
	cout << "\t daysInCourse {";

	/* print each index of daysInDegreesize array without a final comma */
	for (int i = 0; i < daysInDegreesize; i++) {
		if (i < daysInDegreesize - 1) {
			cout << this->numDaysInDegree[i] << ", ";
		}
		else {
			cout << this->numDaysInDegree[i];
		}
	}
	cout << "}\t Degree Program: " << DegreeProgramNames[this->degreeProgram] << endl;

}
