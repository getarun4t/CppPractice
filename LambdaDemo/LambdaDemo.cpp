#include <iostream>

int main() {
	auto a = [](int arg) {return 2 * arg;};
	std::cout << "First free = " << a(4) << std::endl;

	int i = 3;
	auto b = [i](int arg) {return i * arg; };
	std::cout << "Second free = " << b(4) << std::endl;

	int j = 4;
	auto c = [=](int arg) {return j*arg; };
	std::cout << "Third free = " << c(4) << std::endl;

	int k = 4;
	auto d = [&]() {return k++; };
	std::cout << "Fourth free = " << d() << std::endl;
	std::cout << "Ref change = " << k << std::endl;
}