#ifndef TODOMODEL_h
#define TODOMODEL_h

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class TodoList {
	vector<pair<string, string>> items;
public:
	void AddtoList(pair<string, string> *p) {
		items.push_back(*p);
	}

	int size() {
		return items.size();
	}

	string getTask(int index) {
		return items[index].first;
	}

	string getDeadline(int index) {
		return items[index].first;
	}

	void printAll() {
		cout << endl << "Items are:" << endl;
		for (auto i : items) {
			cout << i.first << " with deadline: "<< i.second << endl;
		}
	}
};

class TodoModel {
	unique_ptr<TodoList> item;
public:
	TodoModel() : item(make_unique<TodoList>()) {}

	void addNewItem(string s, string t) {
		pair<string, string> p;
		p.first = s;
		p.second = t;
		item->AddtoList(&p);
	}

	void printItems() {
		item->printAll();
	}
};
#endif// TODOMODEL_h