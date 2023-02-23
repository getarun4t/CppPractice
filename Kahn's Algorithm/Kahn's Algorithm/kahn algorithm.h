
#include<iostream>
#include<list>
#include <queue>
using namespace std;

class Graph {
	int v;
	list<int>* l;
public:
	Graph(int v) {
		this->v = v;
		this->l = new list<int>[v];
	}

	void addEdge(int i, int j) {
		l[i].push_back(j);
	}

	void kahnSort() {
		vector<int> indegree(v);

		for (int i = 0; i < v; i++) {
			for (auto c : l[i]) {
				indegree[c]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < v; i++) {
			if (indegree[i]==0)
				q.push(i);
		}

		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0)
					q.push(nbr);
			}
		}







	}
};