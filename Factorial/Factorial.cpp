#include <iostream>
using namespace std;

int main() {
	int number=0, fact=1;
	cout << "Enter the number \n" ;
	cin >> number;
	for (int i = 1; i <= number; i++) {
		fact = fact * i;
	}
	cout << "The factorial of " << number << " is " << fact;
}