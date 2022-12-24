#include <iostream>
using namespace std;

class PrimeNumber {
public:
	int prime_number(int number);
	int division_checker(int number);
};

int PrimeNumber::prime_number(int number) {
	if (number != 0 && number != 1 && division_checker(number) == 1)
		return 1;
	else
		return 0;
}

int PrimeNumber::division_checker(int number) {
	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	PrimeNumber prime;
	int i=0, count=0;
	while (count < 25) {
		if (prime.prime_number(i) == 1) {
			cout << i << endl;
			count++;
		}
		++i;
	}
}