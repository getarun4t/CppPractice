#include<vector>
#include <iostream>

using namespace std;

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
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < n; l++) {
				cout << board[k][l] << " ";
			}
			cout << endl;
		}
		return true;
	}
	for (int q = 0; q < n; q++){
		if (checkmate(i, q, board, n)) {
			board[i][q] = 1;
			bool success = QueenCheck(board, n, i+1);
			if (success)
				return true;
		}
		board[i][q] = 0;
	}
	return false;

}


int main() {
	int board[20][20] = { 0 };
	int n = 10;
	QueenCheck(board, n, 0);
}