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
	// create a vector to store the structs
	//std::vector <STUDENT_DATA> students;

	////u can add something to a vector using the .pushback, this will add it to the first available index of the vector
	//STUDENT_DATA student1;
	//students.push_back(student1);

	////u can use .pop_back to remove the last ellement in the vector
	//students.pop_back();


	//file i/o starts here
	std::vector <STUDENT_DATA> students;
	STUDENT_DATA tmpStudent;
	string line;
	std::ifstream stData("StudentData.txt");

	if (stData.is_open()) {
		
		while ( getline(stData, line) ) {
			stringstream ss(line);

			getline(ss, tmpStudent.lname, ',');
			getline(ss, tmpStudent.fname, '\n');
			//cout << tmpStudent.lname << "," << tmpStudent.fname << endl; //this will print out the list, but not from the vector
			students.push_back(tmpStudent);
		}
		//cout << students.at(0).fname << students.at(0).lname; //prints out an item from the vector
		stData.close();
	}
	else {
		cout << "file did not open";
	}
	
	
	return 1;
}