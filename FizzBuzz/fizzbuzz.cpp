#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n) {
    vector<string> fizz;
    for (int i = 1; i <= n; i++) {
        if (n % 3 == 0 && n % 5 == 0) {
            fizz.push_back("FizzBuzz");
        }
        else if (n % 3 == 0) {
            fizz.push_back("Fizz");
        }
        else if (n % 5 == 0) {
            fizz.push_back("Buzz");
        }
        else {
            fizz.push_back(to_string(n));
        }
    }
    return fizz;
}

int main() {
    cout << fizzbuzz(10);
    return 0;
}