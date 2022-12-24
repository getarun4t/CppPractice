#include<iostream>
#include<vector>

using namespace std;
int counterm = 0;

vector<int> increasingNumbers(int N) {
	vector<int> c;
	if (counterm == N) {
		return c;
	}
	else {
		counterm++;
		c = increasingNumbers(N);
	}
	c.insert(c.begin(), counterm--);
	return c;
}

int main() {
	int num = 5;
	vector<int> c = increasingNumbers(num);
	for (auto v : c) {
		cout << v << endl;
	}
}
