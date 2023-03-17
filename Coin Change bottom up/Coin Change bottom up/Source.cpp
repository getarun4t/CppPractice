#include<iostream>
#include<vector>

using namespace std;

int minchange(vector<int> coins, int change) {
	vector<int> minArray( change+1, 0 );
	for (int i = 1; i <= change; i++) {
		minArray[i] = INT_MAX;
		for (int c : coins) {
			if (i-c>=0)
				minArray[i] = min(minArray[i], minArray[i - c]+1);	
		}
	}
	return minArray[change] == INT_MAX ? -1 : minArray[change];
}

int main() {
	vector<int> coins = { 1,3,7,10 };
	int change = 25;
	cout << minchange(coins, change);
}