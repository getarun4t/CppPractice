#include<iostream>
#include<vector>

using namespace std;

int modex(int x, int y, int z) {
    int res = 1;    
    x = x % z; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % z;
        y = y >> 1; 
        x = (x * x) % z;
    }
    return res;
}

int main() {
	int x = 2, y = 4, mod = 3;
	cout << modex(x, y, mod);
}