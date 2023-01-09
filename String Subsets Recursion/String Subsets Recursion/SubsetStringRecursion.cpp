#include <iostream>
#include <vector>
#include <string>
using namespace std;

void substrings(char *s, char *n, int i, int j) {
	n[j] = s[i];
	if (s[i] == '\0') {
		cout << n << endl;
		return;
	}
	substrings(s, n, i+1, j+1);
	substrings(s, n, i +1, j);
}

int main() {
	char s[100] = "lorum";
	char j[100];
	substrings(s, j, 0, 0);
}