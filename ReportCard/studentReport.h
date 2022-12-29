#pragma once

#include <string>
using namespace std;

class StudentRecords{
private:
	string name;
	string course;
	char grade;
public:
	StudentRecords(string name, string course, char grade);
	string get_name;
	string get_course;
	char get_grade;
};