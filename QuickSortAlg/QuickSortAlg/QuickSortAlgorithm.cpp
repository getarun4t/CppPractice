#include<iostream>
#include<vector>

using namespace std;

vector<int> quicksort(vector<int>& v, int s, int e) {
	if ((e - s) <= 0)
		return v;
	int p = v[e];
	int i = s - 1;
	for (int k = s; k < e; k++) {
		if (v[k] < p) {
			i++;
			swap(v[i], v[k]);
		}
	}
	swap(v[i + 1], v[e]);

	quicksort(v, s, i);
	quicksort(v, i + 2, e);
	return v;
}

int main() {
	vector<int> v = { 7,5,3,2,1};
	int s = 0;
	int e = v.size() - 1;
	vector<int> v1 = quicksort(v, s, e);
	for (auto v : v1)
		cout << v << endl;
}