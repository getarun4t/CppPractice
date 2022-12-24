#include "studentReport.h"

using namespace std;

StudentRecords::StudentRecords(string name, string course, char grade) {
	name = name;
	course = course;
	grade = grade;
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