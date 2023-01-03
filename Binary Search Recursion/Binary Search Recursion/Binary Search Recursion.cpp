#include<iostream>
#include<vector>

using namespace std;

int finder(vector<int> v, int r, int l, int s) {
	int size = r + ((l - r) / 2);
	if (v[size] == s) {
		return size;
	}
	else if (s > v[size]) {
		return finder(v, size+1, l, s);
	}
	else {
		return finder(v, r, size-1, s);
	}
}

int bsr(vector<int> v, int s) {
	int size = v.size();
	return finder(v, 0, size - 1, s);
}

int main() {
	vector<int> v = { 1, 3, 5, 7, 9 };
	int s = 7;
	cout << "Index is " << bsr(v, s);
}