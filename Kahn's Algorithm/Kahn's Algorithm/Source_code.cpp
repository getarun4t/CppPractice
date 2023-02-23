#include<iostream>
#include "kahn algorithm.h"

using namespace std;

int main() {
	Graph g(6);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(4, 5);
	g.addEdge(3, 5);
	g.kahnSort();

}