#include <iostream>
#include <thread>

class Hello {
public:
	void operator()() {
		std::cout << "Hello Functor !" << std::endl;
	}
};

void hello() {
	std::cout << "Hello World!" << std::endl;
}

int main() {
	std::thread t(hello);
	Hello hello;
	std::thread u(hello);
	t.join();
	u.join();
}