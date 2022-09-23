#include <stdio.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//create a structure to hold student data



struct STUDENT_DATA {
	string fname;
	string lname;
};


int main() {
	


	std::vector <STUDENT_DATA> students;
	STUDENT_DATA tmpStudent;
	string line;
	std::ifstream stData("StudentData.txt");

	if (stData.is_open()) {
		
		while ( getline(stData, line) ) {
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


#ifdef _DEBUG
	// print out the list of students
	cout << "DEBUG Running \n \n";

	for (int i = 0; i < students.size(); i++) {
		cout << students.at(i).lname << "," << students.at(i).fname << endl;
	}
#endif // DEBUG

	
	return 1;
}