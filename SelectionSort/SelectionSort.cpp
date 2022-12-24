#include<iostream>
#include<vector>

using namespace std;

vector<int> SS(vector<int> arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i; j < arr.size(); j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}

int main() {
	vector<int> arr = { 12,11,3,2,9,4,0 };
	arr = SS(arr);
	for (int i : arr) {
		cout << i << endl;
	}
	return(0);
}