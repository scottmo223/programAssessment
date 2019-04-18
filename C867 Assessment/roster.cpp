#include "roster.h"

Roster::Roster(int maxSize) {
	//Provided Data Table
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY"		,
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK"	,
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE"		,
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"		,
		"A5,Robert,Morales,rmora46@my.wgu.edu,31,15,31,45,SOFTWARE"
	};

	cout << "Created roster \n" << endl;
	this->lastIndex = -1;
	this->maxSize = maxSize;
	this->students = new Student*[maxSize]; // create new pointer array to hold student objects

	for (int i = 0; i < maxSize; ++i) {
		ParseStudentId(studentData[i]);
		if (degreeType == "SECURITY") {
			students[i] = new SecurityStudent(studentId, firstName, lastName, email, age, daysInCourse, SECURITY);
			++lastIndex;
		}
		else if (degreeType == "NETWORK") {
			students[i] = new NetworkStudent(studentId, firstName, lastName, email, age, daysInCourse, NETWORKING);
			++lastIndex;
		}
		else if (degreeType == "SOFTWARE") {
			students[i] = new SoftwareStudent(studentId, firstName, lastName, email, age, daysInCourse, SOFTWARE);
			++lastIndex;
		}
		else {
			cout << "Improper or unassigned degree type" << endl;
		}
	}
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
	this->daysInCourse = new int[3];
	for (int i = 0; i < 3; ++i) this->daysInCourse[i] = stoi(studentDataVector.at(i+5));
	degreeType  = studentDataVector.at(8);
	return;
}

//void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree type) {
//	cout << "Add Student" << endl;
//
//}

void Roster::printAll() {
	for (int i = 0; i < maxSize; ++i) {
		cout << i + 1 << "   ";
		students[i]->PrintData();
	}
	return;
}

void Roster::printInvalidEmails() {
	cout << "\nPrint invalid emails: \n" << endl;
	for (int i = 0; i < maxSize; ++i) {
		string email = students[i]->GetEmailAddress();
		int positionAtSign = email.find('@');
		int periodAfterAtSign = email.find('.', positionAtSign);
		if (periodAfterAtSign == -1) cout << "\t" << email << endl;
		else if(email.find(' ') != -1) cout << "\t" << email << endl;
	}
	cout << endl;
	return;
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < maxSize; ++i) {
		if (students[i]->GetStudentId() == studentID) {
			cout << "student ID: " << students[i]->GetStudentId();
			int *tempDays = students[i]->GetDaysInCourse();
			int avgDays = 0;
			for (int j = 0; j < 3; ++j) {
				avgDays += tempDays[j];
			}
			cout << "\tAverage number of days: " << avgDays / 3 << endl;
			break;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	int numberMatches = 0;
	for (int i = 0; i < maxSize; ++i) {
		if (students[i]->GetDegreeProgram() == degreeProgram) {
			++numberMatches;
			cout << numberMatches << "   ";
			students[i]->PrintData();
		}
	}
	return;
}

int main() {
	int maxSize = 5;
	
	//Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.
	cout << "C867 Scripting and Programming\t C++    #000954923   Robert Morales" << endl << endl;
	
	Roster* classRoster = nullptr; 
	classRoster = new Roster(maxSize);   //create classRoster, add each student to classRoster

//	classRoster->printAll();

//	classRoster->printInvalidEmails();

	//classRoster->printAverageDaysInCourse("A4"); //This works to call single student's avgDays
//	for (int i = 0; i < maxSize; ++i) { //loop through all students and print avgDays
//		ostringstream idOSS;
//		idOSS << "A" << i+1;
//		classRoster->printAverageDaysInCourse(idOSS.str()); 
//	}

	classRoster->printByDegreeProgram(SOFTWARE);
	
	
	//***How to send arr as argument and return arr as pointer ***
	/*int days[3] = {10, 20, 30};
	Student poopMan = Student("a1", "bob", "smith", "yahoo@gmail.com", "36", days, SOFTWARE);
	int *tempdays; tempdays = poopMan.GetDaysInCourse();
	cout << poopMan.GetFirstName() << endl;
	for(int i = 0; i < 3; ++i) cout << tempdays[i] << endl;*/
	
	char exitSign = 'a';
	while (exitSign != 'q') {
		

		cout << "\nenter 'q' to quit...";
		cin >> exitSign;
		cout << endl << endl;
	}
	
	return 0;
}