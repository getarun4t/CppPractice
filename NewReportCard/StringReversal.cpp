#include "StringReversal.h"

using namespace std;

string StringReversal::thirikkal(string nere) {
	for (char& c : nere) {
		string kashnam;
		kashnam.push_back(c);
		thirich.insert(0, kashnam);
	}
	return(thirich);
}