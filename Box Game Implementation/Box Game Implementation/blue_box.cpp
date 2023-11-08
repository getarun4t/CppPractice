#include "blue_box.h"

double BlueBox::calculateScore(double absorbed_weight) {
	if (absorbed_weight < smallest) {
		smallest = absorbed_weight;
	}
	if (absorbed_weight > largest) {
		largest = absorbed_weight;
	}

	return cantorPairing(smallest, largest);
}

double BlueBox::cantorPairing(double a, double b) {
	return ((a + b) * (a + b + 1) / 2) + b;
}