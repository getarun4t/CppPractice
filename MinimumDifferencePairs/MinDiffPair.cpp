#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

pair<int, int> FindPair(vector <int> arr1, vector <int> arr2) {
	int n1 = arr1.size();
	int n2 = arr2.size();
	int min_difference = 0;
	pair<int, int> pairs;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			unsigned int temp=0;
			if (arr1[i] > arr2[j]) 
				temp = arr1[i] - arr2[j];
			else
				temp = arr2[j] - arr1[i];
			if (arr1[i] == arr2[j]) {
				pairs.first = arr1[i];
				pairs.second = arr2[j];
				min_difference = 0;
				continue;
			}
			if (min_difference > temp or (i == 0 && j == 0)) {
				pairs.first = arr1[i];
				pairs.second = arr2[j];
				min_difference = temp;
			}
		}
	}
	return pairs;
}
 
int main() {
	vector<int> FirstArr = { 23, 5, 10, 19, 30 };
	vector<int> SecondArr = { 26, 134, 135, 14, 17 };
	pair<int, int> pairs = FindPair(FirstArr, SecondArr);
	cout << "Pairs are: " << pairs.first << " & " << pairs.second;
	return(0);
}
