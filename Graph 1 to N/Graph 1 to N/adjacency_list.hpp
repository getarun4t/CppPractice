#include<iostream>
#include<list>

using namespace std;

class Graph {
	int gSzie;
	list<int>* l;
public:
	Graph(int gSize);
	void addEdge(int i, int j, bool undir=true);
	int getNextItem(int i);
	void printAdjList();
	bool checkPath(int N);
};