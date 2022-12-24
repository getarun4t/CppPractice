#include <cstdio>
#include "counter.h"

const char counted[] = "This is the string to be counted.";
using namespace std;

int main() 
{
	counter c1;
	printf("%i", c1.count_string(counted));
	return 0;
}