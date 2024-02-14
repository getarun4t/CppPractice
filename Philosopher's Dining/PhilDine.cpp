#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>

std::thread t1;
std::thread t2;

class Philosopher {
	bool eat;
	bool think;
public:
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

	bool get_status() {
		if (eat) {
			return true;
		}
		return false;
	}
};

struct Table {
	std::vector<Philosopher> phils;
	std::vector<std::shared_mutex> fork;
	Table(int n) : phils(n), fork(n) {};

	void get_table_status() {
		int philc = 0;
		for (auto& p : phils) {
			if (p.get_status()) {
				std::cout << "Philosoper " << philc << " is eating" << std::endl;
			}
			else {
				std::cout << "Philosoper " << philc << " is thinking" << std::endl;
			}
		}
	}

	void serve_food() {
		for (size_t i = 0; i < fork.size(); ++i) {
			std::unique_lock<std::shared_mutex> lock(fork[i]);
			std::cout << "Serving food to Philosopher " << i << std::endl;
		}
	}
};

int main() {
	Table table(5);
	table.serve_food();
}