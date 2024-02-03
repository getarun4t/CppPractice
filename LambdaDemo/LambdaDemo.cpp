#include <iostream>

int main() {
	int i;

	auto a = [](int arg) {return 2 * arg; };
	std::cout << "First free = " << a(4) << std::endl;


}