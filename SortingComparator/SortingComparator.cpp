#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool func(int a, int b) {
	return a > b;
}

vector<int> comp(vector<int> arr, bool flag) {
	if (flag) sort(arr.begin(), arr.end());
	else sort(arr.begin(), arr.end(), func);
	return arr;
}

int main() {
	vector<int> arr = { 1,4,2,7,4,8,4 };
	bool flag=false;
	arr = comp(arr, flag);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
}