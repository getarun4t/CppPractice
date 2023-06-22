#include"adjacency_list.hpp"
#include<vector>

bool solution(int N, vector<int>& A, vector<int>& B) {
	const int g_size = A.size();
	Graph g(g_size+1);
	for (int i = 0; i < g_size; i++) {
		g.addEdge(A[i], B[i]);
	}
	g.printAdjList();
	return g.checkPath(N);
}


int main() {
	vector<int> A = { 1,2,1,3 };
	vector<int> B = { 2,4,3,4 };
	int N = 4;
	solution(N, A, B) ? cout <<"Present": cout << "Absent";
}