#include<iostream>
#include<vector>

using namespace std;

vector<int> CS(vector<int> arr, int largest) {
	vector<int> freq(largest+1, 0);
	for (int i : arr) {
		freq[i] ++;
	}
	arr.clear();
	for (int i = 0; i < largest+1; i++) {
		while (freq[i] != 0) {
			arr.push_back(i);
			freq[i] --;
		}
	}
	return arr;
}

int main() {
	vector<int> arr = { 3,1,2,5,6,1,5,6,10 };
	int largest = 10;

	arr = CS(arr, largest);
	for (int i : arr) {
		cout << i << endl;
	}
}