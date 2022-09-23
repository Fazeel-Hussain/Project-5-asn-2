#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//create a structure to hold student data

#define PreRelease



struct STUDENT_DATA {
	string fname;
	string lname;
	string email;
};


int main() {
	
#ifdef PreRelease
	cout << "PreRelease is Running" << endl;

	std::vector <STUDENT_DATA> students;
	STUDENT_DATA tmpStudent;
	string line;
	std::ifstream stData("StudentData_Emails.txt");

	if (stData.is_open()) {

		while (getline(stData, line)) {
			stringstream ss(line);

			getline(ss, tmpStudent.lname, ',');
			getline(ss, tmpStudent.fname, ',');
			getline(ss, tmpStudent.email, '\n');
			students.push_back(tmpStudent);
		}
		stData.close();
	}
	else {
		cout << "file did not open";
	}

	
#else 
	cout << "Standard Version running \n";

	std::vector <STUDENT_DATA> students;
	STUDENT_DATA tmpStudent;
	string line;
	std::ifstream stData("StudentData.txt");

	if (stData.is_open()) {

		while (getline(stData, line)) {
			stringstream ss(line);

			getline(ss, tmpStudent.lname, ',');
			getline(ss, tmpStudent.fname, '\n');
			students.push_back(tmpStudent);
		}
		stData.close();
	}
	else {
		cout << "file did not open";
	}
#endif // PreRelease


#ifdef _DEBUG
	// print out the list of students
	cout << "DEBUG Running \n \n";

#ifdef PreRelease
	for (int i = 0; i < students.size(); i++) {
		cout << students.at(i).lname << "," << students.at(i).fname << "," << students.at(i).email << endl;
	}
#else
	for (int i = 0; i < students.size(); i++) {
		cout << students.at(i).lname << "," << students.at(i).fname << endl;
}

#endif // PreRelease

	
#endif // DEBUG


	return 1;
}