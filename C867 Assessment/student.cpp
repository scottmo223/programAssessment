#include "student.h"

Student::Student() {
	studentId = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	studentAge = "";
	this->daysInCourse = new int[3];
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, string age, int daysInCourse[], Degree type) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = age;
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
}

Student::~Student(){
	delete[] daysInCourse;
}

//2a - Accessors
string Student::GetStudentId() {
	return studentId;
}
string Student::GetFirstName() {
	return firstName;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetEmailAddress() {
	return emailAddress;
}
string Student::GetStudentAge() {
	return studentAge;
}
int* Student::GetDaysInCourse() { 
	return daysInCourse;
}
Degree Student::GetDegreeProgram() {
	return degreeType; 
}

//2b - Mutators
void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
	return;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
	return;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
	return;
}
void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}
void Student::SetStudentAge(string studentAge) {
	this->studentAge = studentAge;
	return;
}
void Student::SetDaysCourseComplete(int daysInCourse[]) {
	for (int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
}

void Student::PrintData(){
	int *tempdays = GetDaysInCourse(); //temp holder for daysInCourse
	cout << "First Name: " << GetFirstName() << "\t Last Name: " << GetLastName();
	cout << "\t Age: " << GetStudentAge() << "\t daysInCourse: ";
	cout << "{" << tempdays[0] << ", " << tempdays[1] << ", " << tempdays[2] << "}";
	cout << " Degree Program: " << GetDegreeProgram() << "." << endl;
	return;
}
