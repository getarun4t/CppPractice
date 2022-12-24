#include <iostream>
#include <vector>
using namespace std;

vector<int> krotate(vector<int> arr, int k) {
	for (int i=0; i< k; i++) {
		auto val = arr.back();
		arr.pop_back();
		arr.insert(arr.begin(), val);
	}
	return arr;
}

int main() {
	vector<int> arr = { 1,4,6,78,2,9 }, newvec;
	int k = 2;
	newvec = krotate(arr, k);
	for (int i : newvec) {
		cout << i << endl;
	}
}