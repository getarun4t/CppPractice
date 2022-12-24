// NewReportCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "StringReversal.h"

using namespace std;
/*
class StringReversal {
private:
	string thirich;
public:
	string thirikkal(string nere);
};

string StringReversal::thirikkal(string nere) {
	for (char& c: nere) {
		string kashnam;
		kashnam.push_back(c);
		thirich.insert(0, kashnam);
	}
	return(thirich);
}
*/
int main()
{
	StringReversal reverser;
	string nere;
	cout << "Enter String to be reversed:\n";
	getline(cin, nere);	
	cout << "Reversed form of "<<nere<<" is "<<reverser.thirikkal(nere);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
