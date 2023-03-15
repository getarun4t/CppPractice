#include<iostream>

using namespace std;

int dp[100] = { 0 };

int fib(const int n) {
	dp[1] = 1;
	dp[0] = 0;
	for (int i = 2; i<=n; i++){
		dp[i] = dp[i - 1]+ dp[i-2];
	}
	return dp[n];
}

int main() {
	int n = 5;
	cout << fib(n);
}