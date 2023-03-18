#include<iostream>
#include<vector>

using namespace std;

int minchanger(vector<int> coins, int change, int pos, vector<int> &minArray) {
	if (pos == 0)
		return 0;
	for (auto c : coins){
		if (pos-c >=0){
			if (minArray[pos - c] == INT_MAX)
				minArray[pos - c] = minchanger(coins, change, pos - c, minArray);
			minArray[pos] = min(minArray[pos], minArray[pos - c]+1);
		}
	}
	return minArray[pos];
}

int minchangetopdown(vector<int> coins, int change) {
	vector<int> minArray(change+1, INT_MAX);
	return minchanger(coins, change, change, minArray);
}

int main() {
	int change = 16;
	vector<int> coins = { 1,3,7,10 };
	cout << minchangetopdown(coins, change);

}