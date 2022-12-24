#include <iostream>
#include <vector>

using namespace std;

vector<int> optimize(vector<int> arr) {
	int size = arr.size();
	for (int x = 0; x < size-1; x++)
	{
		int flag = 0;
		for (int y = 0; y < size - x-1; y++)
		{
			if (arr[y] > arr[y + 1]){
				int temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	return arr;
}

int main() {
	vector<int> arr = {1,2,3,4,5,6};
	arr = optimize(arr);
	for (int i : arr) {
		cout << i << endl;
	}
}