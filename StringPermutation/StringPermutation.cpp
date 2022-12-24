#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPermu(string a, string b) {
	if (a.length() != b.length())
		return false;
	else{
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i])
				return false;
		}
	}
	return true;
}

int main() {
	string a = "abocd";
	string b = "dcbia";
	cout << checkPermu(a, b) << endl;
	return (0);
}