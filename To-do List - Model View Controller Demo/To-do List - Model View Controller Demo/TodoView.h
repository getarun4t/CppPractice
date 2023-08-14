#ifndef TODOVIEW_h
#define TODOVIEW_h

#include <iostream>
#include <vector>
#include "TodoModel.h"

using namespace std;

class TodoView {
public:
	void printlist(TodoList* list) {
		cout << "List contents are below: " << endl;
		for (int i = 0; i < list->size(); i++) {
			cout << "Item " << i << ": " << list->getTask(i);
			cout << "with deadline: " << list->getDeadline(i) << endl;
		}
		cout << "***************************" << endl << endl;
	}
};
#endif// TODOVIEW_h