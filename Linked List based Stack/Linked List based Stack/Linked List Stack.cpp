#include<iostream>
#include "ll_stack.h"
#include<string>

using namespace std;

int main() {
	Stack<char> s;
	s.push('a');
	s.push('b');
	s.push('c');

	cout << s.top() << endl;


}