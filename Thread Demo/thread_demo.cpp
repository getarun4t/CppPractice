#include <iostream>
#include <thread>
#include <string>

class Hello {
public:
	void operator()() {
		std::cout << "Hello Functor !" << std::endl;
	}
};

class MemFunDemo {
public:
	void hello() {
		std::cout << "Hello Member Func Thread !" << std::endl;
	}
};

void hello() {
	std::cout << "Hello World!" << std::endl;
}

void hellow(std::string str) {
	std::cout << str << std::endl;
}

void hellom(std::string&& str) {
	std::cout << str << std::endl;
}

void hellon(std::string& reftr) {
	reftr = "Hello Ref Modified Thread !";
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

	//Moved thread argument
	std::string str = "Hello Moved Thread !";
	std::thread x(hellom, std::move(str));

	//Ref thread argument
	std::string reftr = "Hello Ref Thread !";
	std::thread y(hellon, std::ref(reftr));

	//Member Function argument
	MemFunDemo obj;
	std::thread z(&MemFunDemo::hello, &obj);

	t.join();
	u.join();
	v.join();
	w.join();
	x.join();
	y.join();
	z.join();

	std::cout << reftr << std::endl;
}