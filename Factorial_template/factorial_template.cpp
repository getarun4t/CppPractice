#include <iostream>
using namespace std;

template <typename t> 
t tfact(t num) {
	t fact=1, i;
	for (i = 1; i <= num; i++) {
		fact = fact * i;
	}
	return fact;
}

int main() {
	int number = 0, fact = 1;
	cout << "Enter the number \n";
	cin >> number;
	cout << "The factorial of " << number << " is " << tfact(number);
}