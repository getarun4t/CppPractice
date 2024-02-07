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

class threadguard {
	std::thread a;
public:
	explicit threadguard(std::thread&& a): a(std::move(a)){}

	~threadguard() {
		if (a.joinable()) {
			a.join();
		}
	}

	threadguard(const threadguard&)  = delete;
	threadguard& operator =(const threadguard&) = delete;
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

	//Moved thread
	std::string str = "Hello Moved Thread !";
	std::thread x(hellom, std::move(str));

	//Ref thread
	std::string reftr = "Hello Ref Thread !";
	std::thread y(hellon, std::ref(reftr));

	//Member Function Thread
	MemFunDemo obj;
	std::thread z(&MemFunDemo::hello, &obj);

	//Lambda Expression Thread
	std::string lamex = "Hello Lamex Thread !";
	std::thread s([&lamex]() {
		lamex = "Hello Lamex Modified Thread !";
		});

	//Lambda Expression with Argument Thread
	std::thread r([](std::string a, std::string b) {
		std::cout << a << b << std::endl;
		}, "Hello Lambda Expression ", "with Argument Thread !");

	//try-catch Thread
	try {
		std::thread q(hello);
		threadguard(std::move(q));
		throw std::exception();
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << "\n";
	}
	
	r.join();
	s.join();
	t.join();
	u.join();
	v.join();
	w.join();
	x.join();
	y.join();
	z.join();

	std::cout << reftr << std::endl;
	std::cout << lamex << std::endl;
}