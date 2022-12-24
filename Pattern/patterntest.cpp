#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct pattern {
	int calculate(const int x, const int y) {
		int initial = 1, diff_x = 0;
		for (int i = 1; i <= x; i++) {
			initial += i;
			diff_x = i;
		}
		for (int diff = diff_x + 2; diff < y + diff_x + 2; diff++) {
			initial += diff;
		}
		return initial;
	}
};


int main () {
	pattern p;
	pattern p1;
	int x_axis = 0, y_axis = 0;
	cout << "Enter the x position" << endl;
	cin >> x_axis;
	cout << "Enter the y position" << endl;
	cin >> y_axis;
	cout << "Value: " << p.calculate(x_axis, y_axis) << endl;
	cout << "Value: " << p.calculate(1, 2) << endl;
	return 0;
}