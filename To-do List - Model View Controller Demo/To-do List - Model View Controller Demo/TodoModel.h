#ifndef TODOMODEL_h
#define TODOMODEL_h

#include <iostream>
#include <vector>

using namespace std;

class TodoList {
	vector<pair<string, string>> list;
public:
	void AddtoList(pair<string, string>* p) {
		list.push_back(*p);
	}
};

class TodoModel {
	TodoList* list;
public:
	void addNewItem(string s, string t) {
		pair<string, string>* p;
		p->first = s;
		p->second = t;
		list->AddtoList(p);
	}

	void
}
#endif TODOMODEL_h


