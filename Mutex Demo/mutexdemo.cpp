#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<chrono>
#include <shared_mutex>
#include <vector>

using namespace std::literals;

std::mutex mut;
std::mutex strmut;
std::shared_mutex shm;

int shared_value = 2;

void write_task() {
	std::lock_guard<std::shared_mutex> lock(shm);
	++shared_value;
	std::cout << "Writing to shared value now" << std::endl;
}

void read_task() {
	std::shared_lock <std::shared_mutex> sharedlocks(shm);
	using namespace std::literals;
	std::this_thread::sleep_for(1000ms);
	std::cout << "Current shared value : " << shared_value << std::endl;
}

void task(std::string str) {
	strmut.lock();
	for(int i=0; i<5; i++){
		std::cout << str[0] << str[1] << str[2] << std::endl;
	}
	strmut.unlock();
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

	std::vector<std::thread> thread;

	for (int i = 0; i < 20; ++i) {
		thread.push_back(std::thread(read_task));
	}
	thread.push_back(std::thread(write_task));
	for (int i = 0; i < 20; ++i) {
		thread.push_back(std::thread(read_task));
	}
	thread.push_back(std::thread(write_task));

	task1();
	task2();
	a.join();
	b.join();
	c.join();
	for (auto& thr : thread)
		thr.join();
}