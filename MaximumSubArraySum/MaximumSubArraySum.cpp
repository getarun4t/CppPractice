#include <iostream>
#include <vector>

using namespace std;

int maxSubArryFinder(vector<int> arr) {
    int n = arr.size();
    int max_subarray_sum = 0, next_sum = 0;

    for (int i = 0; i < n; i++) {
        next_sum = next_sum + arr[i];
        if (next_sum <= 0) {
            next_sum = 0;
        }
        max_subarray_sum = max(max_subarray_sum, next_sum);
    }
    return max_subarray_sum;
}

int main() {
	vector<int> arr = { -1,2,3,4,-2,6,-8,3 };
	cout << maxSubArryFinder(arr) << endl;
	return (0);
}