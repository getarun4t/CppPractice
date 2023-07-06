#include<iostream>
#include<vector>

using namespace std;


class Node {
	int val;
	Node* next;
public:
	int getVal() {
		return val;
	}
	Node* getNext() {
		return next;
	}
	void setVal(int data) {
		val = data;
	}
	void setNext(Node* next) {
		this->next = next;
	}
};

class LinkedList {
	Node* head;
public:
	LinkedList(int d) {
		head = nullptr;
		if (d != NULL) {
			Node* n = new Node;
			n->setVal(d);
			n->setNext(head);
			head = n;
			cout << endl << "Overloaded Construtor" << endl;
		}
	}

	LinkedList() : LinkedList(NULL) {}

	LinkedList(LinkedList& source) {
		this->head = source.head;
		cout << endl << "Copy Constructor" << endl;
	}
	
	LinkedList& operator=(LinkedList& source) {
		this->head = source.head;
		cout << endl << "Copy Assignment Operator" << endl;
		return *this;
	}

	LinkedList(LinkedList&& source) noexcept : head(nullptr) {
		this->head = source.head;
		source.head = NULL;
		cout << endl << "Move Constructor" << endl;
	}
	
	LinkedList& operator=(LinkedList&& source) {
		this->head = source.head;
		cout << endl << "Move Assignment Operator" << endl;
		source.head = NULL;
		return *this;
	}

	void insertFront(int data) {
		Node* n = new Node();
		n->setVal(data);
		n->setNext(head);
		head = n;
	}

	void deleteFront() {
		if (head == NULL) {
			return;
		}
		Node* temp = head;
		Node* next = head->getNext();
		head = next;
		temp->setNext(nullptr);
		delete temp;
	}

	void display() {
		if (head == NULL) {
			cout << "Nothing to display" << endl;
			return;
		}
		Node* next = head;
		cout << next->getVal() << ", ";
		while(1) {
			if (next->getNext() == nullptr)
				break;
			next = next->getNext();
			cout << next->getVal() << ", ";
		}
		cout << endl;
	}
};

int main() {

	LinkedList l;
	l.display();
	l.insertFront(2);
	l.insertFront(3);
	l.display();
	l.deleteFront();
	l.display();
	l.insertFront(10);
	l.insertFront(20);
	l.display();

	LinkedList overloadedConstr(10);
	overloadedConstr.insertFront(19);
	overloadedConstr.display();
	
	LinkedList copyconstr(l);
	copyconstr.insertFront(323);
	copyconstr.display();

	LinkedList copyAssign;
	copyAssign = l;
	copyAssign.insertFront(233);
	copyAssign.display();
	copyAssign = copyconstr;
	copyAssign.display();

	
	LinkedList moveConstr(move(l));
	moveConstr.display();

	LinkedList moveAssign;
	moveAssign = move(copyAssign);
	moveAssign.display();
}