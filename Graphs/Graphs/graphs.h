#pragma once

#include<iostream>
#include<list>
#include <queue>
using namespace std;

class Graph {
	int v;
	list<int>* l;
public:
	Graph (int v) {
		this->v = v;
		this->l = new list<int>[this->v];
	}

	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if (undir == true)
			l[j].push_back(i);
	}

	void printMap() {
		for (int i = 0; i < v; i++) {
			cout << i << "-->";
			for (auto node : l[i]) {
				cout << node << " ";
			}
			cout << endl;
		}
	}

	void BreadFirstSearch(int source) {
		queue<int> q;
		bool* visited = new bool[v] {0};
		q.push(source);
		visited[source] = true;
		cout << "Bread First Search" << endl;
		cout << " ------------------ " << endl;
		while (!q.empty()) {
			int f = q.front();
			cout << f << endl;
			q.pop();
			for (auto next : l[f]) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = true;
				}
			}
		}
	}

	void depthhelper(int node, bool* visited) {
		visited[node] = true;
		cout << node << endl;
		for (auto v : l[node]) {
			if(!visited[v])
				depthhelper(v, visited);
		}
		return;
	}

	void depthFirstSearch(int source) {
		bool* visited = new bool[v] {0};
		cout << "Depth First Search" << endl;
		cout << " ------------------ " << endl;
		depthhelper(source, visited);
	}
};