
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2) {
    return (p1.second < p2.second);
}

vector<pair<string, int>> sortFruits(vector<pair<string, int>> v, string S) {
    if (S != "price") 
        sort(v.begin(), v.end());
    else
        sort(v.begin(), v.end(), comp);
    return v;
}

int main() {
    vector<pair<string, int>> v = { {"Mango",100}, {"Guava",70}, {"Grapes",40}, {"Apple",60}, {"Banana",30}};
    string s = "price";
    vector<pair<string, int>> vs = sortFruits(v, s);
    for (int i = 0; i < vs.size(); i++) {
        cout << vs[i].first << " , " << vs[i].second << endl;
    }
}