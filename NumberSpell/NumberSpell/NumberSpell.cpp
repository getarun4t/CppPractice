#include<iostream>
#include<vector>

using namespace std;
vector<string> speller = { "zero", "one", "two" };

void spell(int n) {
	if ( n == 0)
		return;
	spell(n / 10);
	cout << speller[n % 10] << " ";
}

int main() {
	int n = 2021;
	spell(n);
}
