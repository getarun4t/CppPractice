#include <iostream>
#include <vector>
using namespace std;


int highest_mountain(vector<int> arr) {
	int n = arr.size();
	int highest = 0;
	for (int i = 1; i < n-2;) {
		if (arr[i] > arr[i + 1] && arr[i - 1] < arr[i]) {
			int count = 0;
			int j;
			for (j = i; j > 0; j--) {
				if (arr[j] > arr[j - 1])
					count++;
				else
					break;
			}
			while (i < n - 2 && arr[i] > arr[i + 1]) {
				count++;
				i++;
			}
			highest = max(count, highest);
		}
		else {
			i++;
		}
	}
	return highest;
}

int main() {
	vector<int> arr{5,6,2,2,2,1,4,5,6,7,4,2,0,1,4,6,7,4 };
	cout << highest_mountain(arr);
	return 0;
}