#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MinSwap(vector<int> arr) {
	vector<int> sorted_arr=arr;
	int sizea = arr.size();
	vector<pair<int, int>> unsorted_pair(sizea);
	sort(sorted_arr.begin(), sorted_arr.end());
	int count = 0;
	for (int i=0; i<sizea; i++){
		unsorted_pair[i].first = arr[i];
		unsorted_pair[i].second = i;
	}
	vector<bool> visited(sizea, false);
	for (int i = 0; i < sizea; i++) {
		if (sorted_arr[i] == arr[i] or visited[i] == true) {
			continue;
		}
		int temp = 0;
		int k = i;
		while (!visited[k]) {
			visited[k] = true;
			int next_index = unsorted_pair[k].second;
			// int next_index = find(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin(); 
			cout << "Current Index: "<< k << endl;
			cout << "Next Index: " << next_index << endl;
			cout << "  " << endl;
			temp = sorted_arr[k];
			arr[k] = sorted_arr[next_index];
			arr[next_index] = temp;
			k = next_index;
			count += 1;
		}
		for (int i : arr){
			cout << i << endl;
		}
		cout << " " << endl;
		for (bool i : visited) {
			cout << i << endl;
		}
		cout << " " << endl;
	}
	for (int i : arr)
		cout << i << endl;
	return count;
}

int main() {
	vector<int> arr = {10, 11, 5,4,3,2,1 };
	cout << "Minimum swaps: " << MinSwap(arr);
	return 0;
}