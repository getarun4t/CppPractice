#include <vector>
#include <iostream>
using namespace std;


int lowerBound(vector<int> A, int Val) {
    int bound = 0, num = 0;
    int n = A.size();
    for (int i=0; i < n;i++) {
        if (Val == A[i]) {
            return Val;
        }
        else if (Val > A[i]) {
            if (bound == 0)
                bound = Val - A[i];
            else
                bound = min(bound, Val - A[i]);
            num = A[i];
        }
    }
    if( bound == 0)
        return -1;
    else
        return num;
}

int main() {
    vector<int> ch = { -1, -1, 2, 3, 5 };
    int Val = 4;
    cout << lowerBound(ch, Val) << endl;
    return(0);
}