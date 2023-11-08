#pragma once

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Player {
	double score;
public:
	Player() : score(0.0) {};
	void addScore(double box_score);
	double getScore();
};
