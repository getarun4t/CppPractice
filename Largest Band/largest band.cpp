#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int highest_band(vector<int> arr) {
	vector<int> band;
	unordered_set<int> band_set(begin(arr), end(arr));
	int new_length = 0;
	vector<int> a;

	for (int i : band_set) {
		int counter = 1;
		vector<int> b;
		if (band_set.find(i - 1) != band_set.end()) {
			continue;
		}
		else {
			counter = 1;
			b.clear();
			b.push_back(i);
			while (band_set.find(i + 1) != band_set.end()) {
				i++;
				counter++;
				b.push_back(i);
			}
		}
		if (counter > new_length){
			new_length = counter;
			a = b;
		}
	}
	for (int l : a)
		cout << l << " ";
	cout << " " << endl;
	return (new_length);
}

int main() {
	vector<int> arr = { 10,9,3,6,0,7,13,12,8,16 };
	cout << highest_band(arr);
	return 0;
}
