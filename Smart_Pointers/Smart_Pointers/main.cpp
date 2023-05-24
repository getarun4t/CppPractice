#include "Trial.hpp"

unique_ptr<vector<shared_ptr<Test>>> make() {
	unique_ptr<vector<shared_ptr<Test>>> temp = make_unique<vector<shared_ptr<Test>>>();
	return temp;
}

void fill(vector<shared_ptr<Test>>& vec, int num) {
	for (int i = 0; i < num; i++) {
		shared_ptr<Test> temp = make_shared<Test>(i);
		vec.push_back(temp);
	}
}

void display(vector<shared_ptr<Test>>& vec) {
	cout << "==============================" << endl;
	for (auto v : vec)
		cout << "\tCurrent data is " << v->get_data() << endl;
	cout << "==============================" << endl;
}

int main() {
	unique_ptr<vector<shared_ptr<Test>>> test_ptr;
	test_ptr = make();
	cout << "How many items do you want to add: \t" ;
	int num;
	cin >> num;
	fill(*test_ptr, num);
	display(*test_ptr);
}