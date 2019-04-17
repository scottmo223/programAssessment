#include "roster.h"

Roster::Roster() {
	//Provided Data Table
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"		,
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK"	,
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE"		,
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"		,
		"A5,Robert,Morales,rmora46@my.wgu.edu,31,15,31,45,SOFTWARE"
	};

	cout << "Created roster" << endl;

	Student *theClassRoster = new Student[10];
	this->studentCount = 0;

	Student **students = new Student*[5];

	for (int i = 0; i < 5; ++i) {
		ParseStudentId(studentData[i]);
		//create new student object - passing in arguments
		students[i] = new SecurityStudent(studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, SECURITY);
		students[i]->printData();
	}
}

Roster::~Roster() {
	cout << "deleting classRosterArray" << endl;
	//delete newStudent;
}

void Roster::ParseStudentId(string studentData) {
	stringstream studentSS(studentData);
	vector<string> studentDataVector;
	//parse string
	for (int i = 0; i < 9; ++i) {
		string substr;
		getline(studentSS, substr, ',');
		studentDataVector.push_back(substr);
	}
	//set to data members
	studentId   = studentDataVector.at(0);
	firstName   = studentDataVector.at(1);
	lastName    = studentDataVector.at(2);
	email       = studentDataVector.at(3);
	age         = studentDataVector.at(4);
	daysInCourse1 = stoi(studentDataVector.at(5));
	daysInCourse2 = stoi(studentDataVector.at(6));
	daysInCourse3 = stoi(studentDataVector.at(7));
	degreeType  = studentDataVector.at(8);
	return;
}

void printAll() {
	
	return;
}

int main() {
	char exitSign = 'a';
	
	Roster* classRoster = nullptr;
	classRoster = new Roster;
	
	while (exitSign != 'q') {
		
		


		cout << "enter 'q' to quit...";
		cin >> exitSign;
		cout << endl << endl;
	}
	
	return 0;
}