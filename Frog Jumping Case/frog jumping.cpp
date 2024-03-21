#include "frog jumping.h"

int solution(std::vector<int>& blocks) {
	int n = blocks.size();
	if (n < 2) {
		std::cout << "Invalid input !" << std::endl;
	}

	std::vector<int> dp_left( n, 0 );
	std::vector<int> dp_right( n, 0 );

	int max_distance = 0;
	for (int i = 1; i < n; ++i) {
		if (blocks[i] <= blocks[i - 1])
			dp_left[i] = dp_left[i-1] + 1;
	}

	for (int i = n - 1; i > 0; --i) {
		if (blocks[i] >= blocks[i - 1])
			dp_right[i - 1] = dp_right[i] + 1;
	}

	for (int i = 0; i< n; ++i){
		max_distance = std::max(max_distance, dp_left[i] + dp_right[i] + 1);
	}
	return max_distance;
}

int main() {
	std::vector<int> blocks{9,8,5,4,8,7,2,1,3,5 };
	std::cout << "Distance b/w blocks: " << solution(blocks) << std::endl;
}