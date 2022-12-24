#include<iostream>

using namespace std;

int fact(int i) {
	if (i == 1) {
		return 1;
	}
	else {
		return i * fact(i - 1);
	}
}

int main() {
	int i = 0;
	cout << "Enter number";
	cin >> i;
	cout << endl;
	cout << fact(i);
}