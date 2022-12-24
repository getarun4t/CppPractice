//Expected Time Complexity: O(N)


#include <bits/stdc++.h>
using namespace std;

vector<int> vec;


void helper(int k, vector<int> v, int i){
    if(i==v.size()){
        return;
    }
    if(v[i]==k){
        vec.push_back(i);
        
    }
    helper(k,v,i+1);
    return;
}

vector<int> findAllOccurences(int k, vector<int> v){
       vec.clear();
       helper(k,v,0);
       return vec;
}

int main() {
    vector<int> input = { 1, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9 };
    int find_num = 3;
    vector<int> output = findAllOccurences(find_num, input);
    for (auto v : output) {
        cout << v << endl;
    }
}