#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto vprint = [&](const vector<int> item) {
	cout << *max_element(item.begin(), item.end()) << endl;
};


/*
void main() {
	vector<vector<int>> matrix = { {1,2}, {3,1} };
	for_each(matrix.begin(), matrix.end(), vprint);
}*/