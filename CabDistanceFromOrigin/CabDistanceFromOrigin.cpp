#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> sortCabs(vector<pair<int, int>> v) {
    // your code  goes here
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            if ((v[i].first + v[i].second) > (v[j].first + v[j].second)) {
                pair<int, int> temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    return v;
}

int main() {
    vector<pair<int, int>> v = { {2,3}, {1,2}, {3,4}, {2,4}, {1,4} };
    vector<pair<int, int>> vs = sortCabs(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << vs[i].first << " ," << vs[i].second << endl;
    }
}
