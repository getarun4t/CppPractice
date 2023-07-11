#include "Linked List Template.h"

int main() {
	LinkedList<string> l;
	l.push_back("Hello");
	l.push_back("World");
	l.push_front("This is");
	l.print_all();

	LinkedList<int> s;
	s.push_back(2);
	s.push_back(3);
	s.push_front(1);
	s.print_all();
}