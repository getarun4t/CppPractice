#include "Trial.hpp"

Test::Test() :data{ 0 } { cout << "\tTest Constructor(" << data << ")" << endl; }
Test::Test(int data) :data{ data } { cout << "\tTest Constructor(" << data << ")" << endl; }
int Test::get_data() const { return data; }
Test::~Test() { cout << "\tTest Destructor(" << data << ")" << endl; }
