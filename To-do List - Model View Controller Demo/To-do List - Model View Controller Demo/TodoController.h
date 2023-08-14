#ifndef TODOCONTROLLER_h
#define TODOCONTROLLER_h

#include <iostream>
#include <vector>
#include <string>
#include "TodoView.h"
#include "TodoModel.h"

using namespace std;

class TodoController {
	TodoView view;
	TodoModel model;
public:
	void run() {
		while (1) {
			string decision = check_decision();


			if (decision == "Yes") {
				addItem();
			}
			else if (decision == "No") {
				if (printItems() == "Yes")
					model.printItems();
				if (askToExit() == "Yes")
					break;
			}
			else {
				cout << "Invalid input " << endl;
				cout << "Please reply either Yes or No" << endl;
			}

		}
	}

	string check_decision() {
		string decision;
		cout << endl << "Do you want to add a to-do list? " << endl;
		cout << "Please reply Yes/No" << endl;
		cin >> decision;
		return decision;
	}

	void addItem() {
		string item, deadline;
		cout << endl<< "Enter the to-do item: " << endl;
		cin >> item;
		cout << "Enter the deadline of the item: " << endl;
		cin >> deadline;
		model.addNewItem(item, deadline);
	}

	string askToExit() {
		string check;
		cout << endl << "Do you want to exit" << endl;
		cout << "Please reply Yes/No" << endl;
		cin >> check;
		return check;
	}


	string printItems() {
		string check;
		cout << endl << "Do you print items" << endl;
		cout << "Please reply Yes/No" << endl;
		cin >> check;
		return check;
	}
};
#endif// TODOCONTROLLER_h

