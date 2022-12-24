#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int tonum(string a) {
	int num = 0, power=0;
	for (int i = a.length() - 1; i >= 0; i-- ) {
		if (a[i] == '1') {
			num = num + pow(2, power);
		}
		power++;
	}
	return num;
}

int main() {
	string a = "111";
	int num = tonum(a);
	cout << num;
}
