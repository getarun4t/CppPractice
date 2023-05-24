#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Test {
	int data;
public:
	Test();
	Test(int data);
	int get_data() const;
	~Test();
};