#include<iostream>
#include<vector>
#include<list>
#include <unordered_set>

using namespace std;

class Graph {
	int gSize;
	list<int>* l;
public:
	Graph(int gSize) {
		this->gSize = gSize;
		l = new list<int>[gSize];
	}

	void addEdge(int a, int b, bool undir=true) {
		l[a].push_back(b);
		if (undir) {
			l[b].push_back(a);
		}
	}

	void printGraph() {
		for (int i = 0; i < gSize; i++) {
			cout << i << " --> [ ";
			for (auto j:l[i]) {
				cout << j <<" ,";
			}
			cout << " ]" << endl;
		}
	}

	bool dfsHelper(unordered_set<int> s, int source, int prev) {
		if (source == prev) {
			return false;
		}

		if (s.find(source) != s.end()) {
			return true;
		}
		s.insert(prev);
		for (auto i : l[source]) {
			if (i == prev) { continue; }
			if (dfsHelper(s, i, source)) { return true; }
		}
		return false;
	}

	bool cycleDetector() {
		unordered_set<int> s;
		return dfsHelper(s, l[0].front(), 0);
	}
};

int main() {
	vector<int> a = { 0, 1, 2, 3, 4, 5 };
	vector<int> b = { 1, 3, 1, 2, 1, 0 };
	int Nodes = 6;
	int gSize = a.size();
	Graph g(Nodes);
	for (int i = 0; i < gSize; i++) {
		g.addEdge(a[i], b[i]);
	}
	g.printGraph();
	g.cycleDetector() and gSize >1 and Nodes >1 ? cout << "Present" <<endl : cout << "Absent" << endl;
}