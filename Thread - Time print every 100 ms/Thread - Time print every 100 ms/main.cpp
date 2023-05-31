#include<iostream>
#include<thread>
#include<chrono>
#include <iomanip>

using namespace std;

void printCurrentTime() {
	chrono::system_clock::time_point now = chrono::system_clock::now();
	time_t now_c = chrono::system_clock::to_time_t(now);

	tm time_info;
	gmtime_s(&time_info, &now_c);

	cout << "Current time:: " << put_time(&time_info, "%FT%T%z") << endl << endl;
}

void sleep() {
	cout << "==================" << endl;
	cout << "Sleeping for 100ms" << endl;
	printCurrentTime();
}

void run() {
	printCurrentTime();
	for (int i = 0; i < 10; i++) {
		thread t(sleep);
		this_thread::sleep_for(chrono::milliseconds(100));
		t.join();
	}
}

int main() {
	run();
}