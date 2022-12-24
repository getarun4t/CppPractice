#include <iostream>
#include <vector>

using namespace std;

int rain_collection(vector<int> arr) {
	int max_valuel = 0, max_valuer=0, i, rain=0, sizea;
	sizea = arr.size();
	vector<int> ltr, rtl;
	ltr.push_back(arr[0]);
	rtl.push_back(arr[sizea-1]);

	for (i = 1; i < sizea; i++) {
		ltr.push_back(max(ltr[i-1], arr[i]));
		rtl.push_back(max(arr[sizea-i-1], rtl[i-1]));
	}
	for (i = 1; i < sizea - 1; i++) {
		rain = rain + min(ltr[i], rtl[sizea-i-1]) - arr[i];
	}
	return rain;
}

int main() {
	vector<int> rain = { 1,0,3,4,6,2,1,5,0,11,4,0 };
	cout << rain_collection(rain);
	return 0;
}