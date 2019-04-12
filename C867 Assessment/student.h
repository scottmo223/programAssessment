#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
public:

	//2c,2e - Constructor, Destructor
	Student();
	~Student();

	//2a - Accessors
	int GetStudentId() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetStudentAge() const;
	int GetDaysCourseComplete() const;
	virtual string GetDegreeProgram() = 0; //pure virtual func - set in subclass

	//2b - Mutators
	void SetStudentId(const int studentId);
	void SetFirstName(const string firstName);
	void SetLastName(const string lastName);
	void SetEmailAddress(const string emailAddress);
	void SetStudentAge(const int studentAge);
	void SetDaysCourseComplete(const int daysCourseComplete[]);
	virtual void SetDegreeType() = 0;  //pure virtual func - set in subclass
	
	//2d - print specific student data
	virtual void printData();
private:
	int* studentId;
	string* firstName;
	string* lastName;
	string* emailAddress;
	int* studentAge;
	int* daysCourseComplete[3]; //FIXME!! Is this correct???
protected:
	string degreeType; //populated in subclasses
};

#endif