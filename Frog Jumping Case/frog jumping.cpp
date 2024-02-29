#include "frog jumping.h"

bool find_if_equal_or_increasing(std::vector<int>& blocks, int i, int j) {
	if (blocks[i] < blocks[j])
		return true;
	return false;
}

bool find_if_equal_or_decreasing(std::vector<int>& blocks, int i, int j) {
	if (blocks[i] < blocks[j])
		return true;
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
		while (find_if_equal_or_decreasing(blocks, j, j + 1)) {
			++temp_size;
			++j;
		}
		while (find_if_equal_or_increasing(blocks, j, j + 1)) {
			++temp_size;
			++j;
		}
	}
}

int main() {
	std::vector<int> blocks{ 1,5,5,3,4 };
	std::cout << "Distance b/w blocks: " << solution(blocks) << std::endl;
}