#include<iostream>
#include<vector>

using namespace std;

void printer(int arr[][4], int r, int c) {
	int count = 0;
	int start_value_r = 0, end_value_r = r;
	int start_value_c = 0, end_value_c = c;
	while (count < r * c) {
		for (int i = start_value_c; i < end_value_c; i++) {
			cout << arr[i][end_value_r - 1] << " ";
			count++;
		}
		end_value_r--;
		for (int i = end_value_c-1; i >= start_value_c; i--) {
			cout << arr[i][end_value_r - 1] << " ";
			count++;
		}
		end_value_r--;
	}

}

int main() {
	int arr[][4] =
	{ {1,2,3,4},
		{12,13,14,5},
		{11,16,15,6},
		{10,9,8,7} };
	int r = 4, c = 4;
	printer(arr, r, c);
}