#include<iostream>
#include<vector>
using namespace std;

int undefended(int length, int breadth, vector<pair<int, int>> arr) {
	vector<pair<int, int>> sorted_1 = arr, sorted2 = arr;
	pair<int, int> start_location = { 0,0 };
	sorted_1.insert(sorted_1.begin(), start_location);
	sorted2.insert(sorted2.begin(), start_location);
	sorted_1.push_back({ length, breadth });
	sorted2.push_back({ length, breadth });
	int largest_area = 0;
	for (int i = 0; i < sorted_1.size(); i++) {
		for (int j = i + 1; j < sorted_1.size(); j++) {
			if (sorted_1[i].first > sorted_1[j].first or (sorted_1[i].first == sorted_1[j].first and sorted_1[i].second > sorted_1[j].second)) {
				auto temp = sorted_1[i];
				sorted_1[i] = sorted_1[j];
				sorted_1[j] = temp;
			}
		}
	}
	for (int i = 0; i < sorted2.size(); i++) {
		for (int j = i + 1; j < sorted2.size(); j++) {
			if (sorted2[i].second > sorted2[j].second or (sorted2[i].second == sorted2[j].second and sorted2[i].first > sorted2[j].first)) {
				auto temp = sorted2[i];
				sorted2[i] = sorted2[j];
				sorted2[j] = temp;
			}
		}
	}

	for (int i = 1; i < sorted_1.size(); i++) {
		int area = 0;
		for (int j = 1; j < sorted2.size(); j++) {
			area = (sorted_1[i].first - sorted_1[i - 1].first-1) * (sorted2[j].second - sorted2[j - 1].second - 1);
			cout << area << endl;
			largest_area = max(largest_area, area);
		}
	}
	
	return largest_area;
}

int main() {
	vector<pair<int, int>> defence = { {3, 8}, {11, 2}, {8, 6} };
	int length=15, breadth=8;
	int undefended_area = undefended(length, breadth, defence);
	cout << "Area: " << undefended_area << endl;
	return(0);
}