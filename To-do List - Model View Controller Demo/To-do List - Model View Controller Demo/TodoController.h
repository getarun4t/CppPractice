#ifndef TODOCONTROLLER_h
#define TODOCONTROLLER_h

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TodoList {
	vector<pair<string, string>> list;
public: 
	void AddtoList(pair<string, string>* p) {
		list.push_back(*p);
	}
};

class TodoController {
	TodoList* list;
public:
	void addNewItem(string s, string t) {
		pair<string, string>* p;
		p->first = s;
		p->second = t;
		list->AddtoList(p);
	}
}

#endif TODOCONTROLLER_h


