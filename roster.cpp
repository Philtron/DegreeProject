#include "roster.h"
#include "student.h"



Roster::Roster() { // Default Constructor
}

/* Parses a string and prepares data for a student object */
void Roster::parse(string row) {

	int comma = row.find(","); // Delimit using commas
	string studentID = row.substr(0, comma);

	
	/* Continue passed first comma */
	int commaStep = comma + 1;
	comma = row.find(",", commaStep);
	string firstName = row.substr(commaStep, (comma - commaStep));

	

	commaStep = comma + 1;
	comma = row.find(",", commaStep);
	string lastName = row.substr(commaStep, (comma - commaStep));

	

	commaStep = comma + 1;
	comma = row.find(",", commaStep);
	string email = row.substr(commaStep, (comma - commaStep));

	

	commaStep = comma + 1;
	comma = row.find(",", commaStep);
	int age = stoi(row.substr(commaStep, (comma - commaStep)));

	

	commaStep = comma + 1;
	comma = row.find(",", commaStep);
	int days1 = stoi(row.substr(commaStep, (comma - commaStep)));

	

	commaStep = comma + 1;
	comma = row.find(",", commaStep);
	int days2 = stoi(row.substr(commaStep, (comma - commaStep)));

	

	commaStep = comma + 1;
	comma = row.find(",", commaStep);
	int days3 = stoi(row.substr(commaStep, (comma - commaStep)));

	

	commaStep = comma + 1;
	comma = row.find(",", commaStep);

	DegreeProgram degree = UNDECLARED;

	/* Check third letter in degree name to determine which degree program student is pursuing */
	if (row[commaStep+2] == 'C') {
		 degree = SECURITY;
	}
	else if (row[commaStep+2] == 'T') {
		 degree = NETWORK;
	}
	else {
		 degree = SOFTWARE;
	}

	

	add(studentID, firstName, lastName, email, age, days1, days2, days3, degree);

}

/* Creates a student object with data received from parse() function.
	   Stores student objects in a Roster Array. */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 }; // create and fill array as student object requires array parameter

	classRosterArray[lastIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);

}

/* Iterates through roster array calling Students print function to display data on all students
	   in Roster */
void Roster::printAll() {
	Student::printHeader();
	for (int i = 0; i < Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

/* Prints each student whose degree program matches input paramaters */
void Roster::printByDegreeProgram(DegreeProgram degree) {
	cout << "Printing students whose degree is " << DegreeProgramNames[degree] << endl;
	Student::printHeader();
	for (int i = 0; i < Roster::lastIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

/* Display Student name and email of any student in roster with an invalid email. Valid emails contain an '@' sign and a '.' and
*  no spaces. */
void Roster::printInvalidEmails() {

	cout << "Printing invalid email addresses: " << endl;

	bool invalidEmail = false;
	for (int i = 0; i < lastIndex; i++) {
		string studentEmail = classRosterArray[i]->getStudentEmail(); 

		// If it doesn't contain both an '@' and a '.' or if it does contain a space then it is invalid
		if ((studentEmail.find('@') == string::npos) || (studentEmail.find('.') == string::npos) || (studentEmail.find(' ') != string::npos)) {
			invalidEmail = true;
			string firstName = classRosterArray[i]->getStudentFirstName();
			string lastName = classRosterArray[i]->getStudentLastName();
			cout << firstName << " " << lastName << ": " << studentEmail << " is invalid." << endl;
		}
	}

	/* If no invalid email addresses are found */
	if (!invalidEmail) {
		cout << "No invalid email addresses." << endl;
	}
	cout << endl;
}

/* Adds up days in each course and prints the average */
void Roster::printAverageDaysInCourse(string studentID) {
	int sum = 0;

	
	/* Iterate through student objects until object with matching student ID is found, then 
	* increment sum variable by each set of days in degree. Divide by 3 to get and then  print average */
	for (int i = 0; i < lastIndex; i++) {
		string workingID = classRosterArray[i]->getStudentID();
		if (workingID == studentID) {
			

			for (int j = 0; j < 3; j++){
				sum += classRosterArray[i]->getNumDaysDegree()[j];
			}
			double average = static_cast<double>(sum) / 3.0;
			

			cout << "ID: " << workingID << " average days in course: " << average << endl;
		}
	}
}

/* Removes a student object from Roster Array*/
void Roster::remove(string studentID) {

	bool foundID = false;

	/* iterate through student objects in roster until we find the matching student ID. When found replace current and further indexes with 
	* index +1 then decrement index list size variable */
	for (int i = 0; i < lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			foundID = true;
			cout << studentID << " found. Removing..." << endl;
			for (int j = i; j < lastIndex; j++) {

				classRosterArray[j] = classRosterArray[j + 1];
			}
			lastIndex--;
			cout << "Done." << endl;
		}
	}

	/* Message when student ID searched for is not found */
	if (!foundID) {
		cout << "ID: " << studentID << " not found." << endl;
	}
}

/* Destructor with print message to indicate it is working. Removes all student objects created by Roster */
Roster::~Roster() {
	cout << "Destroying Roster's objects. ";
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}