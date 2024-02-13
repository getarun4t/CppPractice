#include <mutex>
#include <iostream>
#include <thread>

std::thread t1;
std::thread t2;

class Philosopher {
	bool eat;
	bool think;

	Philosopher() {
		eat = false;
		think = true;
	}

	void start_eating() {
		eat = true;
		think = false;
	}

	void stop_eating() {
		eat = false;
		think = true;
	}
};

int main() {

}