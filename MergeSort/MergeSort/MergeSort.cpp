#include<iostream>
#include<vector>

using namespace std;

vector<int> merger(vector<int> &v, int s, int e, int mid) {
	int i1 = s;
	int i2 = mid + 1;
	vector<int> temp;
	while ((i1 <= mid) and (i2<= e)) {
		if (v[i1] > v[i2]) {
			temp.push_back(v[i2]);
			i2++;
		}
		else {
			temp.push_back(v[i1]);
			i1++;
		}
		
	}
	while (i1 <= mid) {
		temp.push_back(v[i1++]);
	}
	while (i2 <= e) {
		temp.push_back(v[i2++]);
	}
	int k = 0;
	for (int i = s; i <= e; i++) {
		v[i] = temp[k++];
	}
	return v;
}

vector<int> mergesort(vector<int> &v, int s, int e) {
	if (e-s <= 0){
		return v;
	}
	int mid = (s + e) / 2;
	mergesort(v, s, mid);
	mergesort(v, mid+1, e);
	return merger(v, s, e, mid);
}

int main() {
	vector<int> v = { 7,1,6,5 };
	int s = 0;
	int e = v.size() - 1;
	vector<int> v1 = mergesort(v, s, e);
	for (auto v : v1)
		cout << v << endl;
}