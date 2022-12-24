#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> v) {
	int last_val = 0;
	if (v.size() % 2 == 0)
		last_val = v.size() / 2;
	else
		last_val = v.size() - 1;
	for (int i = 0; i <= last_val-1; i++) {
		for (int j = i; j <= v[i].size()/2-i; j++) {
			swap(v[i][j], v[j][v.size() - 1-i]);
			swap(v[i][j], v[v.size() - 1-i][v.size()-1-j]);
			swap(v[i][j], v[v.size() - 1-j][i]);
		}
	}
	return v;
}

int main() {
	vector<vector<int>> v =
	{ {1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
		{13,14,15,16}
};
	v = rotate(v);
	for (int j = 0; j < v.size(); j++) {
		for (int i : v[j]) {
			cout << i << " , ";
		}
		cout << endl;
	}
}