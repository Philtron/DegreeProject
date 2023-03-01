#pragma once
#include <string>

/* Create Enum for student degree programs */

enum  DegreeProgram {SECURITY, NETWORK, SOFTWARE, UNDECLARED}; 

/* Create array with string names to correspond with enum's int values */
static const std::string DegreeProgramNames[] = { "SECURITY", "NETWORK", "SOFTWARE", "UNDECLARED" };