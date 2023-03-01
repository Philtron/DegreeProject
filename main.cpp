/* Final project for WGU's C867 - Scripting and Programming Applications 
*  Written by: Philip Sauer WGU Student ID: 001156531 Email: psauer1@wgu.edu 12/15/2020
*  This program parses information from an array of strings. Using two classes,  it creates student objects and manipulates them 
*  using the roster class */

#include "student.h"
#include "roster.h"


int main() {

	const string studentData[] ={   
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Philip,Sauer,psauer1@wgu.edu,37,14,21,28,SOFTWARE" 
	};



	/* 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name. */

	cout << "C867 - Scripting and Programming Applications using C++" << endl;
	cout << "By Philip Sauer - Student ID: 001156531" << endl << endl;

	/* 2.  Create an instance of the Roster class called classRoster. */
	Roster classRoster; 

	/* 3.  Add each student to classRoster. */
	cout << "Building Roster...";
	int size = sizeof(studentData) / sizeof(studentData[0]); // Determine length of Student Data input
	for (int i = 0; i < size; i++) {
		
		classRoster.parse(studentData[i]); // parse each line in StudentData[] adding student objects to Roster array
		
	}
	cout << " Done. Displaying roster: " << endl;
	classRoster.printAll();

	/* Display Student name and email of any student in roster with an invalid email. Valid emails contain an '@' sign and a '.' and 
	*  no spaces. */
	classRoster.printInvalidEmails(); 

	/*loop through classRosterArray and for each element print average days in course. */
	string IDs[5]; // Build array with student ID's
	for (int i = 0; i < size; i++) { 
		string row = studentData[i];
		int comma = row.find(","); // Delimit using commas
		IDs[i] = row.substr(0, comma);

	}

	/* Iterate through classRoster using student ID's  and print the average days in the students courses */
	cout << "Displaying average days in course for each student by Student ID: " << endl;
	for (int i = 0; i < size; i++) {
		classRoster.printAverageDaysInCourse(IDs[i]);
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	
	cout << "Attempting to remove A3." << endl;
	classRoster.remove("A3"); // Remove student object whose Student ID is A3 from Roster Array
	classRoster.printAll();
	cout << "Attempting to remove A3." << endl;
	classRoster.remove("A3"); // Displays error message as A3 has already been removed.
	cout << endl;

}
