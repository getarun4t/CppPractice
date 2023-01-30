#include <iostream>
#include <stack>

using namespace std;

stack<int> inverter(stack<int> &s, int n) {
	if (s.size() < 1) {
		s.push(n);
		return s;
	}
	int temp = s.top();
	s.pop();
	inverter(s, n);
	s.push(temp);
	return s;
	
}

stack<int> reverser(stack<int> &s) { 
	if (s.empty()) {
		return s;
	}
	int temp = s.top();
	s.pop();
	reverser(s);
	inverter(s, temp);
	return s;
}

int summer(int &n, int &pos, stack<int>& s) {
	if (s.size() == 1) {
		n = n + s.top();
		return n;
	}
	int temp = s.top();
	s.pop();


	summer(n, pos, s);
	pos = pos * 10;
	n = n + pos * temp;
	return n;
}
	

int reverse(int n) {
	stack<int> s;
	while (!(n > 0 && n<9 )) {
		s.push(n % 10);
		n = n / 10;
	}
	s.push(n % 10);
	n = n / 10;
	s = reverser(s);
	int pos = 1;
	n = summer(n, pos, s);
	return n;

}

int main() {

	int n = 654;
	cout << reverse(n) << endl;

}