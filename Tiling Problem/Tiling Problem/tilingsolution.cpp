#include<iostream>
#include<vector>

using namespace std;

int ways(int l, int b) {
	if (l < b)
		return 1;
	else 
		return (ways(l - 1, b) + ways(l - b, b));
}

int main() {
	int l = 3;
	int b = 3;
	cout << ways(l, b);
}