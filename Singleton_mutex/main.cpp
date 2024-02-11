#include "singleton.h"
#include <vector>
#include <thread>

void task() {
	Singleton& single = get_singleton();
	std::cout << &single << std::endl;
}

int main() {
	std::vector<std::thread> threads;

	for (int i = 0; i < 20; ++i) {
		threads.push_back(std::thread(task));
	}

	for (auto& item : threads) {
		item.join();
	}
}