#include "records.h"

using namespace std;

Student::Student(int the_id, string the_name) {
	id = const_id;
	name = const_name;
}

int Student::get_id() {
	return id;
}

string Student::string get_name() {
	return name;
}

Course::Course(int the_id, string the_name, unsigned char the_credits) {
	id = the_id;
	name = the_name;
	credits = the_credits;
}

int Course::get_id() {
	return id;
}

string Course::get_name() {
	return name;
}

unsigned char Course::get_credits() {
	return credits;
}

Grade::Grade(int sid, int cid, char grd) {
	student_id = sid;
	course_id = cid;
	grade = grd;
}

int Grade::get_student_id() {
	return student_id;
}

int Course::get_course_id() {
	return course_id;
}

char Course::get_grade() {
	return grade;
}