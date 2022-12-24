#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

auto prime_check (int number) {
	if (number == 0 || number == 1) {
		return false;
	}
	else {
		for (int i = 2; i <= number / 2; ++i) {
			if (number % i == 0) {
				return false;
				break;
			}
		}
	}
}


int main() {
	auto num=0;
	cout << "Enter the range" << endl;
	cin >> num;
	vector<int> vec(num);
	vector<int> prime;
	iota(vec.begin(), vec.end(), 1);
	cout << "numbers"<< endl;
	for (int i : vec)
		cout << i << endl;
	copy_if(vec.begin(), vec.end(), back_inserter(prime), prime_check);
	cout << "prime"<< endl;
	for (int i : prime)
		cout << i << endl;
	return 0;
}

