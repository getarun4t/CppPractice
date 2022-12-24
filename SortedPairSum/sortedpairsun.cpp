#include <vector>
#include <iostream>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x) {
    int diff = arr[arr.size() - 1] * 2;
    pair<int, int> pairs;

    for (int i = 0; i < arr.size(); i++) {
        int start = i + 1, end = arr.size()-1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int local_diff = abs(x - (arr[i] + arr[mid]));
            if (diff > local_diff) {
                pairs.first = arr[i];
                pairs.second = arr[mid];
                diff = local_diff;
            }
            if ((x - arr[i]) < arr[mid]) {
                end = mid-1;
            }
            else if ((x - arr[i]) > arr[mid]) {
                start = mid+1;
            }
            else {
                pairs.first = arr[i];
                pairs.second = arr[mid];
                return pairs;
            }
        }
    }
    return pairs;
}

int main() {
    vector<int> arr = { 10, 22, 28, 29, 30, 40 };
    int x = 54;
    pair<int, int> pairs = closestSum(arr, x);
    cout << "Pair \n" << pairs.first << "\n" << pairs.second << endl;
    return(0);
}