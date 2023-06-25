#include<iostream>
#include<vector>

using namespace std;

pair<int, int> findSource(vector<vector<string>> field, int b, int l) {
	int source = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < b; j++) {
			if (field[j][i] == "A") {
				pair<int, int> loc;
				loc.first = j;
				loc.second = i;
				return loc;
			}
		}
	}
}

bool checkBreadth(vector<vector<string>> field, int b, int l, int x, int y) {
	for (int i = y; i < b; i++) {
		if (field[x][i] == "x" or field[x][i] == ">" or field[x][i] == "v")
			break;
		else if (field[x][i] == "<")
			return false;
	}
	for (int i = y-1; i >= 0;  i--) {
		if (field[x][i] == "x" or field[x][i] == "<" or field[x][i] == "v")
			return true;
		else if (field[x][i] == ">")
			return false;
	}
	return true;
}

bool checkLength(vector<vector<string>> field, int b, int l, int x, int y) {
	for (int i = x; i >=0; i--) {
		if (field[i][y] == "x" or field[i][y] == ">" or field[i][y] == "<")
			return true;
		else if (field[i][y] == "v")
			return false;
	}
	return true;
}

bool pathHelper(vector<vector<string>> field, int b, int l, int init_a, int init_b) {
	cout << "Current position is (" << init_a << " ," << init_b << ")" << endl;

	if (init_a == l - 1 && init_b == b - 1) {
		cout << "Reached destination : (" << init_a << " ," << init_b << ")" << endl;
		return true;
	}
	if (init_b + 1 < b) {
		if (field[init_a][init_b + 1] == "." &&
			checkLength(field, b, l, init_a, init_b + 1)) {
			field[init_a][init_b + 1] = "A";
			if (pathHelper(field, b, l, init_a, init_b + 1)) {
				return true;
			};
		}
	}
	if (init_a + 1 < l) {
		if (field[init_a + 1][init_b] == "." &&
			checkBreadth(field, b, l, init_a + 1, init_b)) {
			field[init_a + 1][init_b] = "A";
			if (pathHelper(field, b, l, init_a + 1, init_b)) {
				return true;
			};
		}
	}
	if (init_a-1 >=0){
		if (field[init_a - 1][init_b] == "." &&
			checkBreadth(field, b, l, init_a - 1, init_b)) {
			field[init_a - 1][init_b] = "A";
			if (pathHelper(field, b, l, init_a - 1, init_b)) {
				return true;
			};
		}
	}
	if(init_b - 1 >= 0) {
		if (field[init_a][init_b - 1] == "." &&
			checkLength(field, b, l, init_a, init_b - 1)) {
			field[init_a][init_b - 1] = "A";
			if (pathHelper(field, b, l, init_a, init_b - 1)) {
				return true;
			};
		}
	}
	if (field[init_a][init_b] == "A") {
		cout << "Going back (" << init_a << " ," << init_b << ")" << endl;
		return false;
	}
	return true;
}

bool pathCheck(vector<vector<string>> field) {
	bool pos_flag;
	const int b = field.size();
	const int l = field[0].size();
	pair<int, int> Node = findSource(field, b, l);
	int init_a = Node.first;
	int init_b = Node.second;
	if (init_a == l - 1 && init_b == b - 1) {
		cout << "Reached destination : (" << init_a << " ," << init_b << ")" << endl;
		return true;
	}
	return pathHelper(field, l, b, init_a, init_b);
}

int main() {
	vector<vector<string>> field =
	{	{".", ".", "." ,"<", "."},
		{".", ".", "v", "A", ">"},
		{".", "<", "x", ".", ">"},
		{".", ".", "x", "x", "."} };

	cout << pathCheck(field) << endl;
}