#include <stdio>

int a[5] = [100,211,33,42,17]

int main() {
	float avg=0.0;
	int total = 0;
	for (i = 0, i < 5, i++) {
		total = total + a[i];
	}
	avg = total / 5;
	cout << "Average is " << avg << endl;

}