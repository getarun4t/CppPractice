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
    uint64_t s = binaryStringToNumber(S);
    while(s != 0){
        if (s & 1){
            s = s -1;
        }
        else {
            s = s/2;
        }
        iter += 1;
    }
    return iter;
}

int main() {
    string S = "10101";
    cout << solution(S);
}

