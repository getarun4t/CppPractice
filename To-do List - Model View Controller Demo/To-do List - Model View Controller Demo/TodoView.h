#ifndef TODOVIEW_h
#define TODOVIEW_h

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

class TodoView {
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

#endif TODOVIEW_h


