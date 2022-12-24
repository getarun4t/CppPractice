#include<iostream>
#include<vector>
using namespace std;

int FU(vector<int> v) {
	int res = 0;
	for (auto x : v)  res ^= x;
	return res;
}

int main() {
	vector<int> v = { 1, 2, 3, 1, 4, 2, 3,5,4 };
	cout << FU(v);
}