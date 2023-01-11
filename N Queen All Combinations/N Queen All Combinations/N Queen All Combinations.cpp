#include<vector>
#include <iostream>

using namespace std;
int counter = 0;

bool checkmate(int i, int q, int board[][20], int n) {
	for (int k = 0; k < i; k++) {
		if (board[k][q]) {
			return false;
		}
	}
	int a = i, b = q;
	while ((a >= 0) && (b >= 0)) {
		if (board[a][b]) {
			return false;
		}
		a--; b--;
	}
	a = i, b = q;
	while ((a >= 0) && (b < n)) {
		if (board[a][b]) {
			return false;
		}
		a--; b++;
	}
	return true;
}

bool QueenCheck(int board[][20], int n, int i) {
	if (i == n) {
		counter = counter + 1;
		return true;
	}
	bool success=false;
	for (int q = 0; q < n; q++) {
		if (checkmate(i, q, board, n)) {
			board[i][q] = 1;
			success = QueenCheck(board, n, i + 1);
		}
		board[i][q] = 0;
	}
	if (success)
		return true;
	return false;

}


int main() {
	int board[20][20] = { 0 };
	int n = 8;
	QueenCheck(board, n, 0);
	cout << counter;
}