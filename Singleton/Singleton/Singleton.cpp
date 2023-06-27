#include<iostream>

using namespace std;

class Singleton {
	static Singleton* instance;
	Singleton() {};
public:
	static Singleton* getInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		cout << instance << endl;
		return instance;
	}

	void SingletonPrint() {
		cout << "this is a Singleton: " << getInstance() <<endl;
	}

};

Singleton* Singleton::instance = nullptr;

int main() {
	Singleton* s = Singleton::getInstance();
	s->SingletonPrint();
	s->getInstance();
	s->SingletonPrint();
}