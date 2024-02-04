#include <iostream>
#include <thread>
#include <string>

class Hello {
public:
	void operator()() {
		std::cout << "Hello Functor !" << std::endl;
	}
};

void hello() {
	std::cout << "Hello World!" << std::endl;
}

void hellow(std::string str) {
	std::cout << str << std::endl;
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

	//Thread argument
	std::thread w(hellow, "Hello Argumented Thread !");

	t.join();
	u.join();
	v.join();
	w.join();
}