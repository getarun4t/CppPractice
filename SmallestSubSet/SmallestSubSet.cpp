#include <iostream>
#include <vector>

using namespace std;

void SmallestSubSet(vector<int> arr) {
	auto sizea = arr.size();
	int wn_start = 0, wn_start_key = 0, wn_end = 0, wn_end_key = 0;
	int ch_key_start = 0, ch_key_end = 0, length =0;
	for (int i = 0; i < sizea - 2;) {
		if (arr[i] > arr[i + 1]) {
			wn_start = arr[i];
			wn_start_key = i;
			i++;
			int j = 0, k=0, ch_key_start_temp = 0, ch_key_end_temp = 0;
			for (j = i; j < sizea - 2;) {
				if (arr[j] < arr[j + 1]) {
					wn_end = arr[j];
					wn_end_key = j;
					j++;
					break;
				}
				j++;
			}
			for (k = 0; k <= i-1; k++) {
				if (arr[k] > arr[j]) {
					ch_key_start_temp = k;
					break;
				}
			}
			for (k = j; k < sizea - 1; k++) {
				if (arr[i - 1] < arr[k]) {
					ch_key_end_temp = k;
					break;
				}
			}
			if (length < (ch_key_end_temp - ch_key_start_temp)) {
				ch_key_start = ch_key_start_temp;
				ch_key_end = ch_key_end_temp;
				length = ch_key_end - ch_key_start;
			}
		i = j;
		}
		else
		{
			i++;
		}
	}
	cout << "Sub-set left index: " <<ch_key_start << endl;
	cout << "Sub-set right index: " << ch_key_end << endl;
	cout << "Length of sub-set " << length << endl;
}

int main() {
	vector<int> toset = { 1,2,3,7,5,4,6,8,9,10,11,12 };
	SmallestSubSet(toset);
	return 0;
}