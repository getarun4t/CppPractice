#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int>::iterator highest_row, lowest_column;
	int index = 0;
	vector<vector<int>> matrix = { {1,2}, {3,4} };
	vector<int> column;
	for (vector<int> row : matrix) {
		highest_row = max_element(row.begin(), row.end());
		index = highest_row-row.begin();
		for (int k = 0; k < size(row); ++k) {
			column.push_back(matrix[k][index]);
		}
		lowest_column = min_element(column.begin(), column.end());
		*highest_row == *lowest_column ? cout << "Value is " << *highest_row << " at index[" <<index<<","<<lowest_column-column.begin()<<"]" : cout << endl;
	}
	return 0;
}
