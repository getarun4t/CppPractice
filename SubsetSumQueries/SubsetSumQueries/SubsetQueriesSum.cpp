#include<vector>
#include<iostream>
#include <bitset>

using namespace std;

vector<bool> subsetSum(vector<int> v, vector<int> q)
{
    int n = q.size();
    vector<bool> b(n);

    bitset<10000> bit;
    bit.reset();
    bit[0] = 1;

    for (int i = 0; i < v.size(); ++i)
        bit |= (bit << v[i]);

    for (int i = 0; i < n; i++)
    {
        int x = q[i];
        bit[x] ? b[i] = true : b[i] = false;
    }

    return b;
}

int main() {
	vector<int> num = { 1, 2, 3 };
    vector<int> query = { 5, 3, 8 };
    vector<bool> boli = subsetSum(num, query);
    for (auto v : boli) {
        cout << v << "  ";
    }
}
