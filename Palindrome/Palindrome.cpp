#include <iostream>
#include <string>

using namespace std;

bool check_palindrome(string chara) {
	bool flag = true;
	for (int i = 0; i < (size(chara)/2); i++) {
		if (chara[i] == chara[size(chara) - i])
			flag = false;
	}
	return flag;
}

int main() {
	string name = "abba";
	cout << check_palindrome(name) << endl;
	return (0);
}