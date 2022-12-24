#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string removedup(string a) {
	sort(a.begin(), a.end());
	string b;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != a[i + 1])
			b.push_back(a[i]);			
	}
	return b;
}

int main() {
	string a = "aaabmmmmcd";
	a = removedup(a);
	for (int i = 0; i<a.length(); i++)
		cout << a[i];
	return(0);
}