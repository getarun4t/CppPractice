#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

template <typename T> 
T counter(vector<T> const& vec) {
	T j = 0;
	for (T i : vec) {
		j++;
	}
	return j;
}

int main() {
	vector<int> v = {1,2,45,5,65,6,76};
	vector<long double> vs = {1.1,2.332,45.244,5.33,65.16,7.6 };
	cout << counter(v) << endl;
	cout << counter(vs) << endl;
}