#include <iostream>
#include <vector>

using namespace std;

int largestElement(vector<int> arr) {
	int largest = 0;
	for (int i : arr) {
		largest = max(largest, i);
	}
	return largest;
}

int main() {
	vector<int> arr ={ -3, 4, 1, 2, 3 };
	cout << largestElement(arr) << endl;
	return 0;
}