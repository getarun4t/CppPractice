#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v = {1,2,3,4,5,5,6,7};
	for (vector<int>::iterator p = v.begin(); p < v.end(); ++p) {
		cout << *p << endl;
	}
	return 0;
}