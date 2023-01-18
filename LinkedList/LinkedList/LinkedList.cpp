#include<iostream>
#include "list.h"

using namespace std;

int main() {
	List l;
	l.push_front(1);
	l.push_front(0);
	l.insert(30, 1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.pop_front();
	l.pop_back();

	l.print_list();
	l.delete_pos(2);
	cout << l.recursiveSearch(2) << " is the location" << endl;
	cout << " " << endl;
	l.print_list();

}