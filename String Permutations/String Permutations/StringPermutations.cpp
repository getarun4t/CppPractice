#include <iostream>
#include <vector>
#include <string>
using namespace std;

void substrings(string s, string n, int i, int j) {
	int s1 = s.length();
	if (i >= s1-1) {
		cout << n << endl;
		return;
	}
	substrings(s, n, i + 1, j + 1);
	for (int p = j+1; p < s1; p++) {
		swap(n[j], n[p]);
		substrings(s, n, i + 1, j+1);
	}
	
}

int main() {
	string s = "lorum";
	string n = s;
	substrings(s, n, 0, 0);
}