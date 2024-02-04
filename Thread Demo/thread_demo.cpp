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
	// Normal thread
	std::thread t(hello);

	//Functor Thread
	Hello hello;
	std::thread u(hello);

	//Lambda Thread
	std::thread v([]() {
		std::cout << "Hello Lambda !" << std::endl;
		});

	t.join();
	u.join();
	v.join();
}