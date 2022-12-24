#include <iostream>
using namespace std;

int ConverttoBinary(int num) {
	int ans = 0, mul=1;
	while (num > 0) {
		int last_bit = num & 1;
		if (last_bit) {
			ans = ans + mul;
		}
		mul = mul * 10;
		num = num >> 1;
	}
	return ans;
}

int main() {
	int num;
	cout << "Enter the number: ";
	cin >> num;

	cout << "Binary is: " << ConverttoBinary(num);

}

