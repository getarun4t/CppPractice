#include <iostream>
#include <algorithm>


using namespace std;

template <typename T> 
T summer(T var) {
	return var;
};

template<typename T, typename... Args>
T summer(T first, Args... args){
	return first + summer(args... );
}

int main() {
	cout << summer(1,2,3,4,4,5,5,5,5,0);
	return 0;
}