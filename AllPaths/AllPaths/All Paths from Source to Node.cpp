#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> result;

vector<vector<int>> recur(vector<vector<int>>& graph, vector<int>& path, int i, int j, int s) {

    if (i == s - 1) {
        result.push_back(path);
        return result;
    }
    
    for (int a = 0; a < graph[i].size(); a++) {
        path.push_back(graph[i][a]);
        recur(graph, path, graph[i][a], 0, s);
        path.pop_back();
    }
    return result;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    path.push_back(0);
    int v = graph.size();
    return recur(graph, path, 0, 0, v);
}

int main() {
    vector<vector<int>> graph = { {1,2,3},
        {2},
        {3},
        {} };
    vector<vector<int>> r = allPathsSourceTarget(graph);
    for (auto v : r) {
        for (auto f : v) {
            cout << f;
        }
        cout << endl;
    }
}
