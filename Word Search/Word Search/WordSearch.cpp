#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

bool path_checker(vector<vector<char>>& board, string word, set<vector<int>> covered, int x, int y, int i, bool first_location) {
	//end case
	if (i >= word.size()) {
		return true;
	}
	//entry case
	if (!first_location) {
		for (int a = 0; a < board.size(); a++) {
			for (int b = 0; b < board[a].size(); b++) {
				if (board[a][b] == word[0]) {
					vector<int> c = { a, b };
					covered.insert(c);
					if(path_checker(board, word, covered, a, b, i + 1, true))
						return true;
				}
			}
		}
		return false;
	}

	//recursive case
	if (x < board.size() - 1) {
		if ((board[x + 1][y] == word[i]) && !(covered.find({ x + 1, y }) != covered.end())) {
			vector<int> c = { x + 1, y };
			covered.insert(c);
			if (path_checker(board, word, covered, x + 1, y, i + 1, first_location))
				return true;
			
		}
	}
	if (y < board[0].size() - 1) {
		if ((board[x][y + 1] == word[i]) && !(covered.find({ x, y + 1 }) != covered.end())) {
			vector<int> c = { x, y + 1 };
			covered.insert(c);
			if(path_checker(board, word, covered, x, y + 1, i + 1, first_location))
				return true;
		}
	}
	if (x > 0) {
		if ((board[x - 1][y] == word[i]) && !(covered.find({ x - 1, y }) != covered.end())) {
			vector<int> c = { x - 1, y };
			covered.insert(c);
			if(path_checker(board, word, covered, x - 1, y, i + 1, first_location))
				return true;
		}
	}
	if (y > 0) {
		if ((board[x][y - 1] == word[i]) && !(covered.find({ x, y - 1 }) != covered.end())) {
			vector<int> c = { x, y - 1 };
			covered.insert(c);
			if(path_checker(board, word, covered, x, y - 1, i + 1, first_location))
				return true;
		}
	}
	else {
		return false;
	}
	return false;
}

bool wordSearch(vector<vector<char>>& board, string word)
{
	set<vector<int>> covered;
	return path_checker(board, word, covered, 0, 0, 0, false);
}


int main() {
	//ABCESFCSADEE
	vector<vector<char>> board = { {'A', 'B', 'C', 'E'},
									{'S', 'F', 'C', 'S'},
									{'A', 'D', 'E', 'E'} };
	string word = "ABCD";
	cout << wordSearch(board, word);
}