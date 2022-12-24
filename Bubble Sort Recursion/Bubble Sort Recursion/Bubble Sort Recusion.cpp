#include<iostream>
#include<vector>
using namespace std;

void bub(int arra[], int n, int j) {
	if (n == 1) {
		return; 
	}
	if (j == n - 1) {
		bub(arra, n - 1, 0);
		return;
	}
	if (arra[j] > arra[j + 1]) {
		swap(arra[j], arra[j+1]);
	}
	bub(arra, n, j+1);
}

int main() {
	int arra[] = {8,6,19,2,1,9,4,10,3};
	int n = sizeof(arra) / sizeof(int);
	bub(arra, n, 0);
	for (auto a : arra)
		cout << a << " ";
}