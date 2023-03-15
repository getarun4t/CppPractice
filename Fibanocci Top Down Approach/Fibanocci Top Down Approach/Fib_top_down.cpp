#include<iostream>
#include<vector>

using namespace std;
int dp[100] = { 0 };


int fib(int n) {
	if ((n == 1) or (n == 2))
		return 1;
	else if (n == 0)
		return 0;
	else {
		if (dp[n] != 0){
			cout << "used dp for " << n << " which is "<< dp[n] << endl;
			return dp[n];
		}
		else {
			return dp[n] = fib(n - 1) + fib(n - 2);
		}
	}
}

int main() {
	int n = 20;
	cout << fib(n);
}