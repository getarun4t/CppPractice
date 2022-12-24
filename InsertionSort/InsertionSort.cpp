#include<iostream>
#include<vector>

using namespace std;

vector<int> IS(vector<int> a) {
	for (int i = 0; i < a.size()-1; i++) {
		int j = i+1;
		while (j>0 and a[j-1] > a[j]) {
			int temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			j--;
		}
	}
	return a;
}

int main() {
	vector<int> arr = { 12,11,3,2,9,4,0 };
	arr = IS(arr);
	for (int i : arr) {
		cout << i << endl;
	}
}