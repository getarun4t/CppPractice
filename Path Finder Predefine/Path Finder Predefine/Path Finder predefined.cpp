#include<iostream>
#include<vector>

using namespace std;

pair<int, int> findSource(vector<vector<string>> field, int b, int l) {
	int source = 0;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < l; j++) {
			if (field[i][j] == "A") {
				pair<int, int> loc;
				loc.first = i;
				loc.second = j;
				return loc;
			}
		}
	}
}

vector<vector<string>> pathPredefine(vector<vector<string>> field) {
	int source = 0;
	int k = 0;
	for (int i = 0; i < field.size(); i++) {
		k = 0;
		for (int j = 0; j < field[0].size(); j++) {
			if (field[i][j] == ">") {
				for (int k = j; k < field.size(); k++) {
					if (field[i][k] == "x" or field[i][k] == "v" or field[i][k] == "<") {
						break;
					}
					else {
						field[i][k] = ">";
					}
				}
			}
			if (field[i][j] == "x")
				k = j;
			if (field[i][j] == "v") {
				k = j;
				for (int s = i; s < field.size(); s++) {
					if (field[s][j] == "x" or field[s][j] == ">" or field[s][j] == "<") {
						break;
					}
					else{
						field[s][j] = "x";
					}
				}
			}
			if (field[i][j] == "<") {
				for (int l = j; l >= k; l--) {
					field[i][l] = "<";
				}
			}
		}
	}
	return field;
}


bool pathHelper(vector<vector<string>> field, int b, int l, int current_b, int current_l) {
	cout << "Current position is (" << current_b << " ," << current_l << ")" << endl;

	if (current_b == b - 1 && current_l ==l - 1) {
		cout << "Reached destination : (" << current_b << " ," << current_l << ")" << endl;
		return true;
	}
	if (current_l + 1 < l) {
		if (field[current_b][current_l + 1] == "." ) {
			field[current_b][current_l + 1] = "A";
			if (pathHelper(field, b, l, current_b, current_l + 1)) {
				return true;
			};
		}
	}
	if (current_b + 1 < b) {
		if (field[current_b + 1][current_l] == "." ) {
			field[current_b + 1][current_l] = "A";
			if (pathHelper(field, b, l, current_b + 1, current_l)) {
				return true;
			};
		}
	}
	if (current_b - 1 >= 0) {
		if (field[current_b - 1][current_l] == ".") {
			field[current_b - 1][current_l] = "A";
			if (pathHelper(field, b, l, current_b - 1, current_l)) {
				return true;
			};
		}
	}
	if (current_l - 1 >= 0) {
		if (field[current_b][current_l - 1] == "." ) {
			field[current_b][current_l - 1] = "A";
			if (pathHelper(field, b, l, current_b, current_l - 1)) {
				return true;
			};
		}
	}
	if (field[current_b][current_l] == "A") {
		cout << "Going back (" << current_b << " ," << current_l << ")" << endl;
		return false;
	}
	return true;
}

bool pathCheck(vector<vector<string>> field) {
	bool pos_flag;
	const int b = field.size();
	const int l = field[0].size();
	pair<int, int> Node = findSource(field, b, l);
	int current_b = Node.first;
	int current_l = Node.second;
	if (current_b == l - 1 && current_l == b - 1) {
		cout << "Reached destination : (" << current_b << " ," << current_l << ")" << endl;
		return true;
	}
	vector<vector<string>> field1 = pathPredefine(field);
	return pathHelper(field1, l, b, current_b, current_l);
}

int main() {
	vector<vector<string>> field =
	{	{">", ".", "." ,"v", "<"},
		{"A", ".", ".", ".", "."},
		{".", ".", "x", "<", "."},
		{".", "x", ".", ".", "x"},
		{".", ".", ".", "x", "."} };

	cout << pathCheck(field) << endl;
}