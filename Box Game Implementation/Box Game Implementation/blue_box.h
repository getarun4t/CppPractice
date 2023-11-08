#pragma once

#include "box.h"

class BlueBox :public Box {
	double largest;
public:
	BlueBox(double weight) : Box(weight), largest(weight) {};
	double calculateScore(double absorbed_weight) override;
	double cantorPairing(double a, double b);
};
