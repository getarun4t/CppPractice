#include "game.h"

void Game::printScore(string state) {
	cout << state << " score below: " << endl;
	cout << "Player A: " << A.getScore() << endl;
	cout << "Player B: " << B.getScore() << endl << endl;
}

void Game::play(vector<double> weights) {
	Box* b1 = dynamic_cast<Box*>(&g1);
	Box* b2 = dynamic_cast<Box*>(&g2);
	Box* b3 = dynamic_cast<Box*>(&l1);
	Box* b4 = dynamic_cast<Box*>(&l2);

	while (!weights.empty()) {
		for (int i = 0; i < 2 && !weights.empty(); i++) {
			if (i == 0) {
				A.addScore(GetLightestBoxScore(b1, b2, b3, b4, weights.front()));
			}
			else {
				B.addScore(GetLightestBoxScore(b1, b2, b3, b4, weights.front()));
			}
			weights.erase(weights.begin());
			printScore();
		}
	}
	findWinner();
}

void Game::findWinner() {
	if (A.getScore() > B.getScore()) {
		cout << "Player A wins" << endl;
	}
	else {
		cout << "Player B wins" << endl;
	}
	printScore("Final");
}

double Game:: GetLightestBoxScore(Box* a, Box* b, Box* c, Box* d, double weight) {
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
