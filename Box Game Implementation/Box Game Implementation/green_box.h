#pragma once

#include "box.h"

class GreenBox :public Box {
public:
	GreenBox(double weight) : Box(weight) {};
	double calculateScore(double absorbed_weight) override;
};
