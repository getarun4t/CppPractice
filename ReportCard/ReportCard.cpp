// ReportCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class StudentRecords {
public:
	string name;
	string course;
	char grade;

	StudentRecords(string name, string course, char grade);
	string get_name();
	string get_course();
	char get_grade();
	void print_data();
};

StudentRecords::StudentRecords(string n, string c, char g) {
	name = n;
	course = c;
	grade = g;
}

string StudentRecords::get_name() {
	return name;
}

string StudentRecords::get_course() {
	return course;
}

char StudentRecords::get_grade() {

	return grade;
}

void StudentRecords::print_data() {
	cout << get_name() << endl;
	cout << get_course() << endl;
	cout << get_grade() << endl;


}

int main()
{

	StudentRecords student("Arun", "C++", 'A');


	student.print_data();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
