#include <iostream>

using namespace std;
class DemoA {
	int a;
public:
	void printdemo() {
		cout << "Base class" << endl;
	}
};

class DemoB:public DemoA {
	int b;
public:
	void printdemo() {
		cout << "Derived class" << endl;
	}
};

int main() {
	DemoA *a;
	DemoB b;
	a = &b;
	a->printdemo();
	b.printdemo();
	return 0;
}