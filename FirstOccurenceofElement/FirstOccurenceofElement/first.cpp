#include <iostream>
 
using namespace std;


int findocc(int a[], int f, int n) {
	if (n == 0)
		return -1;
	else if (a[0] == f)
		return 0;
	int pos = findocc(a + 1, f, n - 1);
	if (pos != -1) {
		return pos+1;
	}
	return -1;
}


int main() {
	int a[] = { 1,4,7,9,2,5 };
	int n = sizeof(a) / sizeof(int);
	int f = 15;
	cout << findocc(a,f, n);
}