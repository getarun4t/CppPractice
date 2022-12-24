#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto vowel_checker(char c) {
	string vowels = "aeiouAEIOU";
	return vowels.find(c) != string::npos;
}

int main() {
	string s;
	cout << "Enter the sentence" << endl;
	getline(cin, s);
	auto iterator = remove_if(s.begin(), s.end(), vowel_checker);
	s.erase(iterator, s.end());
	cout << s << endl;
	return 0;
}