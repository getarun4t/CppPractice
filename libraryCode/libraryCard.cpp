#pragma once
#include <iostream>
#include <cstring>
using namespace std;

struct LibraryCard
{
	string name;
	string author;
	int year;
	int publish_year;
	float some_value;
};

int main() {
	LibraryCard dvc = { "Da Vinci Code", "Dan Brown", '2010', '2111', 1.23f};
	cout << dvc.author <<"\n";
	cout << dvc.name << "\n";
	cout << dvc.year << "\n";
	cout << dvc.publish_year << "\n";
	cout << dvc.some_value << "\n";
}
