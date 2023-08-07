#ifndef TODOCONTROLLER_h
#define TODOCONTROLLER_h

#include <iostream>
#include <string>

using namespace std;

class TodoList {
	string task;
	int time;
};

class TodoController {
	int size_m;
	TodoList* t[size_m];
public:
	TodoController() : size_m(1) {};

}

#endif TODOCONTROLLER_h


