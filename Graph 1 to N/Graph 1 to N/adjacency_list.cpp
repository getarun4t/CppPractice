#include"adjacency_list.hpp"

Graph::Graph(int gSize) {
	this->gSzie = gSize;
	l = new list<int>[gSize];
}

void Graph::addEdge(int i, int j, bool undir) {
	l[i].push_back(j);
	if (undir) {
		l[j].push_back(i);
	}
}

int Graph::getNextItem(int i) {
	l[i].begin();
	return i;
}

void Graph::printAdjList() {
	for (int i = 1; i < gSzie; i++) {
		cout << i << "-->";
		for (auto k : l[i]) {
			cout << k << " , ";
		}
		cout << endl;
	}
}

bool Graph::checkPath(int N)
{
	for (int i = 1; i < N; i++) {
		bool flag=false;
		for (auto k : l[i]) {
			if (k == i + 1) {
				flag = true;
				break;
			}
		}
		if (!flag)
			return false;
	}
	return true;
}
