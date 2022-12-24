#include <iostream>

using namespace std;

int fib(int i) {
	if (i == 1)
		return 1;
	else if (i == 0)
		return 1;
	else {
		return (fib(i-1) + fib(i - 2));
	}
}

int main() {
	int i = 0;
	cout << "Enter the number";
	cin >> i;
	cout << fib(i);
}