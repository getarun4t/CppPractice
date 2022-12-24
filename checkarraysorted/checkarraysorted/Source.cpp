#include <iostream>

using namespace std;

bool check(int a[], int i) {
	if (i == 1 or i == 0)
		return true;
	else if ((a[0] < a[1]) and check(a+1, i-1))
		return true;
	else
		return false;
}

int main() {
	int a[] = { 1,2,3,2 };
	int i = sizeof(a) / sizeof(int);
	cout << check(a, i);
}