#include "frog jumping.h"

bool find_if_equal(std::vector<int>& blocks, int i) {
	if (i+1 < blocks.size()) {
		if (blocks[i] == blocks[i+1])
			return true;
	}
	return false;
}

bool find_if_increasing(std::vector<int>& blocks, int i) {
	if (i + 1 < blocks.size()) {
		if (blocks[i] < blocks[i + 1])
			return true;
	}
	return false;
}

bool find_if_equal_or_decreasing(std::vector<int>& blocks, int i) {
	if (i+1 < blocks.size()) {
		if (blocks[i] >= blocks[i+1])
			return true;
	}
	return false;
}

int solution(std::vector<int>& blocks) {
	if (blocks.size() < 2) {
		std::cout << "Invalid input !" << std::endl;
	}

	int i = 0;
	int max_size = 0;
	while (i < blocks.size()) {
		int j = i;
		int temp_size = 1;
		while (find_if_equal_or_decreasing(blocks, j)) {
			++temp_size;
			++j;
		}
		while (find_if_equal(blocks, j)) {
			++temp_size;
			++j;
		}
		while (find_if_increasing(blocks, j)) {
			++temp_size;
			++j;
		}
		if (max_size < temp_size)
			max_size = temp_size;
		++i;
	}
	return max_size;
}

int main() {
	std::vector<int> blocks{9,8,5,4,8,7,2,1,3,5 };
	std::cout << "Distance b/w blocks: " << solution(blocks) << std::endl;
}