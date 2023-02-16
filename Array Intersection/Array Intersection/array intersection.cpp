#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> final;
	unordered_map<int, int> inter;
	for (int i = 0; i < nums1.size(); i++) {
		inter[nums1[i]]++;
	}

	for (int i = 0; i < nums2.size(); i++) {
		if (inter[nums2[i]] > 0) {
			final.push_back(nums2[i]);
			inter[nums2[i]] = 0;
		}
	}
	sort(final.begin(), final.end());
	return final;
}

int main() {
	vector<int> v1 = { 1,2,2,1 };
	vector<int> v2 = { 2,2 };
	v2 = intersection(v1, v2);
	for (auto v : v2)
		cout << v;
}