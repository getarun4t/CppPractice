#pragma once

#include "blue_box.h"
#include "green_box.h"
#include "player.h"


class Game {
	GreenBox g1;
	GreenBox g2;
	BlueBox l1;
	BlueBox l2;
	Player A;
	Player B;
	void printScore(string state = "Current");
	void findWinner();
	double GetLightestBoxScore(Box* a, Box* b, Box* c, Box* d, double weight);
public:
	void play(vector<double> weights);
	Game() : g1(0.0), g2(0.1), l1(0.2), l2(0.3) {};
};
