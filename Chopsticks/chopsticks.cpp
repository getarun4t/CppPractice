#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int FindPairsNumber(vector<int> arr, int d) {
	int count = 0;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size()-1; i=i+2) {
		if ((arr[i+1] - arr[i]) <= d){
			count++;
		}
	}
	return count;
}


int main() {
	vector<int> length = { 1, 3, 3, 9, 4, 8 };
	int total = 2;
	int pairs = FindPairsNumber(length, total);
	cout << pairs;
	return 0;
}