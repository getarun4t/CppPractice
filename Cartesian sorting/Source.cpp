#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> sorter(vector<pair<int, int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i+1; j < arr.size(); j++) {
			if (arr[i].first > arr[j].first or (arr[i].first == arr[j].first and arr[i].second > arr[j].second)) {
				auto temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}

int main() {
	vector<pair<int, int>> arr = { {0,0} , {3,4}, {5,5}, {3,5} , {1,2}, {0, -1} };
	arr = sorter(arr);
	for (auto i : arr) {
		cout << i.first << " : " << i.second << endl;
	}
	return(0);
}