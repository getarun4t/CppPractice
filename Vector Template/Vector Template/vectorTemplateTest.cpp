#include "Vector.h"

int main() {
	Vector<int> v;
	v.print_all();
	v.push_back(5);
	v.push_back(10);
	v.push_front(3);
	v.print_all();
	v.push_front(2);
	v.print_all();
	v.push_front(1);
	v.print_all();
	v.delete_back();
	v.print_all();
	cout << "Printing using operator overloading" << endl;
	cout << "Entry at index 2:  " << v[2] << endl;

	Vector<string> s;
	s.print_all();
	s.push_back("Hello");
	s.push_back("World");
	s.print_all();
	s.push_front("New");
	s.print_all();
	s.delete_back();
	s.print_all();
	cout << "Printing using operator overloading" << endl;
	cout << "Entry at index 2:  " << s[2] << endl;
}