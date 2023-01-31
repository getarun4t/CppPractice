#include<iostream>
#include<vector>

using namespace std;

vector<int> nextgreater(vector<int> v) {
	vector<int> n;
	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1) {
			n.push_back(-1);
			break;
		}
		int j = i + 1;
		while (v[i] >= v[j]) {
			if (j == v.size() - 1) {
				break;
			}
			j = j + 1;
		}
		for (int k = i; k < j; k++) {
			if (j == v.size() - 1) {
				n.push_back(-1);
				continue;
			}
			n.push_back(v[j]);
		}
		i = j-1;
	}
	return n;
}

int main() {
	vector<int> v = { 4, 5, 2, 0 };
	v = nextgreater(v);
	for (auto i : v) {
		cout << i << endl;
	}
}