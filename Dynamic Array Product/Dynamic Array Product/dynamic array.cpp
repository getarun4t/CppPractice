#include<iostream>

using namespace std;


int* dynamic_arr(const int a[], const int a_s, const int b[], const int b_s)
{
	int* ptr{ nullptr };
	ptr= new int[a_s * b_s];
	int k = 0;
	for (auto i = 0; i < a_s; i++) {
		for (auto j = 0; j < b_s; j++) {
			ptr[k] = a[i] * b[j];
			k++;
		}
	}
	return ptr;
}


int main() {
	int a[3]{ 1,2,3 };
	int b[4]{ 2,3,4,5 };
	int* c = dynamic_arr(a, 3, b, 4);
	for (auto i = 0; i < 12; i++) {
		cout << c[i] << endl;
	}
	delete[] c;
}

