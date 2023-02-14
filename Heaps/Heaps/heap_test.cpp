#include "heaps.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	heap h;
	h.insert(2);
	h.insert(10);
	h.insert(5);
	h.insert(4);
	h.insert(11);
	h.insert(1);
	h.remove_top();
	cout << h.get_min();
}