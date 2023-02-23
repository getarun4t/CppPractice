#include<iostream>
#include "graphs.h"

using namespace std;

int main() {
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(2, 3);
	g.addEdge(0, 2);
	g.addEdge(1, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.printMap();
	g.BreadFirstSearch(0);
	g.depthFirstSearch(0);
}