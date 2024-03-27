#include "frog jumping.h"
#include <thread>
#include <algorithm>


int solution(std::vector<int>& blocks) {
	int n = blocks.size();
	if (n < 2) {
		std::cout << "Invalid input !" << std::endl;
	}

	std::vector<int> dp_left( n, 0 );
	std::vector<int> dp_right( n, 0 );

	auto calc_left = [&blocks, &dp_left, &n]() {
		for (int i = 1; i < n; ++i) {
			if (blocks[i] <= blocks[i - 1])
				dp_left[i] = dp_left[i - 1] + 1;
		}
	};

	auto calc_right = [&blocks, &dp_right, &n]() {
		for (int i = n - 1; i > 0; --i) {
			if (blocks[i] >= blocks[i - 1])
				dp_right[i - 1] = dp_right[i] + 1;
		}
	};

	std::thread t1(calc_left);
	std::thread t2(calc_right);

	t1.join();
	t2.join();

	int max_distance = 0;
	for (int i = 0; i< n; ++i){
		max_distance = std::max(max_distance, dp_left[i] + dp_right[i] + 1);
	}
	return max_distance;
}

int main() {
	std::vector<int> blocks{9,4,2,4,5,6,1,3,6,7,4,3,4};
	std::cout << "Distance b/w blocks: " << solution(blocks) << std::endl;
}