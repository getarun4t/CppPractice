#include <iostream>

using namespace std;


int lastocc(int a[], int f, int n) {
	if (n == 0)
		return -1;
	int pos = lastocc(a + 1, f, n - 1);
	if (pos == -1) {
		if (a[0] == f)
			return 0;
		else
			return -1;
	}
	else
		return pos+1;
	
}


int main() {
	int a[] = { 1,4,7,15,9,2,15,4 };
	int n = sizeof(a) / sizeof(int);
	int f = 15;
	cout << lastocc(a, f, n);
}