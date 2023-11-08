#include "player.h"

void Player::addScore(double box_score) {
	this->score += box_score;
}

double Player::getScore() {
	return this->score;
}