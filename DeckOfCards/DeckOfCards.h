#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Cards {
	const string card_number[13] = {"A", "2" , "3" , "4" , "5" , "6" , "7" , "8" , "9" , "T" , "J" , "Q" , "K" };
	const string card_types[4] = { "s", "d", "h", "c" };

public:
	vector <string> deck;

	vector <string> new_deck(int size=1) {
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < 4; k++) {
				for (int j = 0; j < 13; j++) {
					deck.push_back(card_number[j] + card_types[k]);
				}
			}
		}
		return deck;
	}

	int deck_size(vector <string> deck_check) {
		return deck_check.size();
	}
	
	vector <string> shuffle_deck(vector <string> deck_to_shuffle) {
		random_shuffle(deck_to_shuffle.begin(), deck_to_shuffle.end());
		return deck_to_shuffle;
	}

	void print_deck(vector <string> deck_to_print) {
		for (string card : deck_to_print) {
			cout << card << "\n";
		}
	}

	pair<string, vector <string>> deal_card(vector <string> deck_to_pop) {
		string card = deck_to_pop.back();
		deck_to_pop.pop_back();
		return make_pair(card, deck_to_pop);
	}


};