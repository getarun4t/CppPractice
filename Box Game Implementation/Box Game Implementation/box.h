#pragma once

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Box {
protected:
	double weight;
	double total_weight;
	vector<double> absorbed_weights;
	double score;
	double smallest;
public:
	Box(double weight) : weight(weight), smallest(weight), score(0.0), total_weight(0.0) {};
	virtual double calculateScore(double absorbed_weight) { return 0.0; };
	double getScore();
	double getSmallest();
};