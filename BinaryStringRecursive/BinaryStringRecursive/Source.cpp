#include <iostream>
#include <vector>

using namespace std;

vector<string> overall_string;

vector<string> binaryStringFinder(string s, int n) {
	if (s.empty()) {
		if(n!=1)
			binaryStringFinder(s + '1' + '0', n - 2);
		else
			binaryStringFinder(s + '1', n - 1);
		binaryStringFinder(s + '0', n - 1);
		return overall_string;
	}
	if (n < 1) {
		overall_string.insert(overall_string.begin(), s);
		return overall_string;
	}
	else if (n == 1) {
		if (s.back() != '1')
			binaryStringFinder(s + '1', n - 1);	
		binaryStringFinder(s + '0', n - 1);
	}
	else if (s.back() == '0') {
		binaryStringFinder(s + '1', n - 1);
		binaryStringFinder(s + '0', n - 1);
	}
	else {
		binaryStringFinder(s + '0', n - 1);
	}
	return overall_string;
}

vector<string> binaryStrings(int n) {
	string element;
	return binaryStringFinder(element, n);
}

int main() {
	int num = 4;
	vector<string> strings = binaryStrings(num);
	for (int i = 0; i < strings.size(); i++) {
		cout << strings[i] << endl;
	}
}