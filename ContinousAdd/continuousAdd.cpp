#include <iostream>

using namespace std;

auto continuousAdd = [](int initial, int addby) {
	int total = initial;
	return [total, addby] () mutable {
		total += addby;
		return total;
	};
};

int main() {
	auto l1 = continuousAdd(10, 3);
	cout << l1() << endl;
	cout << l1() << endl;
}
