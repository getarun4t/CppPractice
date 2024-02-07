#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<chrono>

using namespace std::literals;

std::mutex mut;

void task(std::string str) {
	mut.lock();
	for(int i=0; i<5; i++){
		std::cout << str[0] << str[1] << str[2] << std::endl;
	}
	mut.unlock();
}

void task1() {
	std::cout << "task1 is trying to lock mutex" << std::endl;
	mut.lock();
	std::cout << "task1 has locked mutex" << std::endl;
	std::this_thread::sleep_for(500ms);
	std::cout << "task1 unlocked mutex" << std::endl;
	mut.unlock();
}

void task2() {
	std::this_thread::sleep_for(100ms);
	std::cout << "task2 is trying to lock mutex" << std::endl;
	while (!mut.try_lock()) {
		std::cout << "task2 couldn't lock mutex" << std::endl;
		std::this_thread::sleep_for(100ms);
	}
	std::cout << "task2 has locked mutex" << std::endl;
	std::this_thread::sleep_for(500ms);
	std::cout << "task2 unlocked mutex" << std::endl;
	mut.unlock();
}

int main() {
	std::thread a(task, "abc");
	std::thread b(task, "def");
	std::thread c(task, "ghi");

	task1();
	task2();
	a.join();
	b.join();
	c.join();
}