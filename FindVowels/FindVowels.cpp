#include <iostream>
#include<string>

using namespace std;

string findvow(string a) {
	string b;
	for (char c : a) {
		if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
			b.push_back(c);
		}
	}
	return b;
}

int main() {
	string a = "kdjfkjdaiencvkjn";
	a = findvow(a);
	for (char s : a) {
		cout << s;
	}
}