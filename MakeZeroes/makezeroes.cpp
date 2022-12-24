#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> makezero(vector<vector<int>> v) {
	vector<int> exc;
	for (int i = 0; i < v.size(); i++) {
		if(find(v[i].begin(), v[i].end(), 0) != v[i].end()){
			int flag = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j] == 0 and (find(exc.begin(), exc.end(), j) != exc.end())) {
					continue;
				}
				else if(v[i][j] == 0) {
					exc.push_back(j);
					flag = 1;
					for (int k = 0; k < v.size(); k++) {
						v[k][j] = 0;
					}
				}
			}
			if (flag == 1) {
				for(int k = 0; k<v[i].size(); k++){
					v[i][k] = 0;
				}
			}
		}
	}
	return v;
}

int main() {
	vector<vector<int>> v = { {5, 4, 3, 9}, {2, 0, 7, 6}, {1, 3, 4, 0}, {9, 8, 3, 4} };
	v = makezero(v);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}