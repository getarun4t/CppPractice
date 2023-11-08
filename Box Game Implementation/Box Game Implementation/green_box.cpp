#include"green_box.h"

double GreenBox::calculateScore(double absorbed_weight) {
	int start = -3;
	int divisor = 3;
	absorbed_weights.push_back(absorbed_weight);
	int vector_length = absorbed_weights.size();
	if (vector_length < 3) {
		start = 0;
		divisor = vector_length;
	}
	for (int i = vector_length - start - 1; i < vector_length; i++) {
		score = score += absorbed_weights[i];
	}
	score = score / divisor;

	if (absorbed_weight < smallest or smallest == 0.0) {
		smallest = absorbed_weight;
	}

	return score * score;
}