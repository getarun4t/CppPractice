#include<iostream>

using namespace std;

int friendsPairing(int num) {
	if (num <= 0)
		return 0;
	else if ((num == 1) or (num == 2))
		return num;
	else
		return friendsPairing(num - 1) + ((num - 1) * friendsPairing(num - 2));
}

int main() {
	int n=4;
	cout << friendsPairing(n);
 }