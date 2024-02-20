#include <iostream>
#include <thread>
#include <vector>
#include <shared_mutex>
#include <future>
#include <chrono>

std::promise<bool> prom;
std::future<bool> fut= prom.get_future();

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
		std::vector<std::promise<void>> promises(fork.size());
		std::vector<std::future<void>>	futures;

		for (auto i = 0; i < fork.size(); ++i) {
			futures.push_back(promises[i].get_future());
		}

		for (size_t i = 0; i < fork.size(); ++i) {
			using namespace std::chrono_literals;
			std::thread([&](size_t index) {
				std::unique_lock<std::shared_mutex> lock(fork[index]);
				std::cout << "Serving food to Philosopher " << index << std::endl;
				std::this_thread::sleep_for(2000ms);
				promises[index].set_value();
				}, i).detach();
		}

		for (auto& future : futures) {
			future.wait();
		}
	}
};

int main() {
	Table table(5);
	table.serve_food();
}