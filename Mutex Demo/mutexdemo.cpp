#include<iostream>
#include<thread>
#include<mutex>
#include<string>

std::mutex mut;

void task(std::string str) {
	mut.lock();
	for(int i=0; i<5; i++){
		std::cout << str[0] << str[1] << str[2] << std::endl;
	}
	mut.unlock();
}

int main() {
	std::thread a(task, "abc");
	std::thread b(task, "def");
	std::thread c(task, "ghi");

	a.join();
	b.join();
	c.join();
}