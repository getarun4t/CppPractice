#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascal(int N) {
	vector<vector<int>> arr;
	for (int i = 1; i <= N; ++i) {
		vector<int> temp;
		for (int j = 1; j <= i; ++j) {
			if ( ((i > 2) and !(j == 1)) and ((i > 2) and !(j == i))) {
				{
					temp.push_back(arr[i - 2][j - 2] + arr[i - 2][j - 1]);
				}
			}
			else {
				temp.push_back(1);
			}
			
		}
		arr.push_back(temp);
	}
	return arr;
}

int main()  {
	int N = 10;
	vector<vector<int>> pas;
	pas =	pascal(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < pas[i].size(); j++) {
			cout << pas[i][j] << " ";
		}
		cout << endl;
	}
}