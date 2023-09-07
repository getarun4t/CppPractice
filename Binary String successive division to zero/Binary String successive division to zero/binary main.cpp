/*
* Write a program to successively perform the following on a binary string
* 1. if odd, substract by 1
* 2. if even, divide by 2
* Print the number of iterations required till the binary number reaches 0
*/

#include <iostream>
#include <string>

using namespace std; 

int solution(string& S) {
    int iter = 0;
    while (S != "0") {
        if (S.back() == '1')
            S[S.length() - 1] = '0';
        else 
            S = S.substr(0, S.length() - 1);
        iter += 1;
    }
    return iter;
}

int main() {
    string S = "10101";
    cout << solution(S);
}

