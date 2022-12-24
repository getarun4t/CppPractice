#include <iostream>
using namespace std;

template <int fibanocci>
struct fib {
	enum {
		value = fib<fibanocci-1>::value + fib<fibanocci - 2>::value
	};
};

template <>
struct fib<0> {
	enum {
		value = 0
	};
};

template <>
struct fib<1> {
	enum {
		value = 1
	};
};


int main() {
	cout << fib<1>::value << endl;
	cout << fib<2>::value << endl;
	cout << fib<3>::value << endl;
	cout << fib<4>::value << endl;
	cout << fib<5>::value << endl;
	cout << fib<6>::value << endl;
	cout << fib<7>::value << endl;
}