#include<iostream>
#include<thread>

using namespace std;

void printer() {
	cout << "This is printer" << endl;
}

void run() {
	thread t([] {
		cout << "Thread 1" << endl;
		});
	t.join();
	thread f(printer);
	f.join();

	cout << "this is main" << endl;
}

void main() {
	run();
}