#include "Vector.h"

int main() {
	Vector<int> t{ 1, 2, 3, 4, 5 };
	t.print_all();

	Vector<int> t1(t);
	t1.print_all();

	Vector<int> t2;
	t2 = t1;
	t2.print_all();

	Vector<int> t3 = move(t2);
	t3.print_all();
	t2.print_all();



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