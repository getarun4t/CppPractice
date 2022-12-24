#include <iostream>
#include <vector>
#include "DeckOfCards.h"

using namespace std;

int main() {
	Cards deck_obj;
	pair<string, vector <string>> deck_pair;
	vector<string> new_deck1 = deck_obj.new_deck(1);
	vector<string> new_deck2 = deck_obj.shuffle_deck(new_deck1);
	deck_pair = deck_obj.deal_card(new_deck2);
	cout << deck_pair.first;
}

