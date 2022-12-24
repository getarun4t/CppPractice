#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> findocc(vector<int> input, int find) {
	vector<int> occ;
	if (input.begin() == input.end()) {
		return occ;
	}
	occ = findocc(vector<int>(input.begin() + 1, input.end()), find);
	transform(occ.begin(), occ.end(), occ.begin(), [](int x) { return x + 1; });
	if (input[0] == find)
		occ.insert(occ.begin(), 0);
	return occ;
}

int main() {
	vector<int> input = { 1, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9 };
	int find_num = 3;
	vector<int> output = findocc(input, find_num);
	for(auto v: output) {
		cout << v << endl;
	}
}