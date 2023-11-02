/*
* The goal is to implement the mechanics of a simple game and write test cases for them.
* The rules of the game are :
* -There are two types of boxes, green and blue.
* -Both can absorb tokens of a given weight, which they add to their own total weight.
* -Both are initialized with a given initial weight.
* -After a box absorbs a token weight, it outputs a score.
* -Green and blue boxes calculate the score in different ways :
* -A green box calculates the score as the square of the mean of the 3 weights that it most recently absorbed(square of mean of all absorbed weights if there are fewer than 3).
* -A blue box calculates the score as Cantor's pairing function of the smallest and largest weight that it has absorbed so far, i.e. pairing(smallest, largest), where pairing(0, 1) = 2
* -The game is played with two green boxes with initial weights 0.0 and 0.1, and two blue boxes with initial weights 0.2 and 0.3.
* -There is a list of input token weights.Each gets used in one turn.
* -There are two players, A and B.Both start with a score of 0.
* -The players take turns alternatingly.Player A starts.
* -In each turn, the current player selects one of the boxes with the currently smallest weight, and lets it absorb the next input token weight.Each input weight gets only used once.
* -The result of the absorption gets added to the current player's score.
* -When all input token weights have been used up, the game ends, and the player with highest score wins.
 */

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

	virtual double calculateScore(double absorbed_weight) { return 0.0; }

	double getScore() {
		return this->score;
	}

	double getSmallest() {
		return this->smallest;
	}
};

class BlueBox:public Box {
	double largest;
public:
	BlueBox(double weight) : Box(weight), largest(weight) {};

	double calculateScore(double absorbed_weight) override {
		if (absorbed_weight < smallest) {
			smallest = absorbed_weight;
		}
		if (absorbed_weight > largest) {
			largest = absorbed_weight;
		}

		return cantorPairing(smallest, largest);
	}

	double cantorPairing(double a, double b) {
		return ((a + b) * (a + b + 1) / 2) + b;
	}
};

class GreenBox :public Box {
public:
	GreenBox(double weight) : Box(weight) {};

	double calculateScore(double absorbed_weight) override {
		int start = -3;
		int divisor = 3;
		absorbed_weights.push_back(absorbed_weight);
		int vector_length = absorbed_weights.size();
		if (vector_length < 3) {
			start = 0;
			divisor = vector_length;
		}
		for (int i = vector_length - start; i <= vector_length; i++) {
			score = score += absorbed_weights[i];
		}
		score = score / divisor;

		if (absorbed_weight < smallest) {
			smallest = absorbed_weight;
		}

		return score * score;
	}
};

class Player {
	double score;
public:
	Player() : score(0.0) {};

	void setScore(double score){
		this->score = score;
	}

	double getScore() {
		return this->score;
	}
};

void play(vector<double> weights) {
	void findWinner(Player*, Player*);
	double GetLightestBoxScore(Box*, Box*, Box*, Box*, double);

	GreenBox g1(0.0);
	GreenBox g2(0.1);
	BlueBox l1(0.2);
	BlueBox l2(0.3);

	Box* b1 = dynamic_cast<Box*>(&g1);
	Box* b2 = dynamic_cast<Box*>(&g2);
	Box* b3 = dynamic_cast<Box*>(&l1);
	Box* b4 = dynamic_cast<Box*>(&l2);


	Player A;
	Player B;

	for (auto player : { A, B }) {
		if (!weights.empty()) {
			player.setScore(GetLightestBoxScore(b1, b2, b3, b4, weights.front()));
			weights.erase(weights.begin());
		}
		else {
			break;
		}
	}

	findWinner(&A, &B);
}

void findWinner(Player* A, Player* B) {
	if (A->getScore() > B->getScore()) {
		cout << "Player A wins" << endl;
	}
	else {
		cout << "Player B wins" << endl;
	}
}

double GetLightestBoxScore(Box* a, Box* b, Box* c, Box* d, double weight) {
	double lowest_weight = numeric_limits<double>::max();
	Box* box_with_lowest_weight = nullptr;
	for (Box* box : { a,b,c,d }) {
		if (lowest_weight > box->getSmallest()) {
			lowest_weight = box->getSmallest();
			box_with_lowest_weight = box;
		}
	}
	box_with_lowest_weight->calculateScore(weight);
	return box_with_lowest_weight->getScore();
}

int main() {
	vector<double> weights = { 1,2,3,4 };
	play(weights);
}