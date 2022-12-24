#include<iostream>
#include<vector>

using namespace std;

int power(int n, int m) {
	if (m == 0) {
		return 1;
	}
	else if(m&1) {
		return n*power(n, m/2)*power(n, m/2);
	}
	else {
		return power(n, m / 2)* power(n, m / 2);
	}
}

int main() {
	int n = 3;
	int m = 5;
	cout << power(n, m);
}