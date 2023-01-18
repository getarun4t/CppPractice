#include<iostream>

using namespace std;
class List;

class Node {
	int data;
	
public:
	Node* next;
	Node(int d):data(d), next(NULL){}
	friend class List;

	int get_data() {
		return data; 
	}

	~Node() {
		if (next != NULL) {
			delete next;
		}
		cout << "deleting " << data << endl;
	}
};

class List{
	Node* head;
	Node* tail;

	int searchHelper(Node* start, int value) {
		if (start == NULL)
			return -1;
		if (start->data == value) {
			return 0;
		}
		int subid = searchHelper(start->next, value);
		if (subid == -1)
			return -1;
		return subid + 1;
	}

public:
	List() : head(NULL), tail(NULL) {}

	Node* begin(){
		return head;
	}

	void push_front(int data) {
		if (head == NULL){
			Node* n = new Node(data);
			head = tail = n;
		}
		else {
			Node* n = new Node(data);
			n-> next = head;
			head = n;
		}
	}

	void push_back(int data) {
		if (head == NULL) {
			Node* n = new Node(data);
			head = tail = n;
		}
		else {
			Node* n = new Node(data);
			tail->next = n;
			tail = n;
		}
	}

	void insert(int data, int pos) {
		if (pos == 0) {
			push_front(data);
			return;
		}
		Node* temp = head;
		for (int jump = 1; jump < pos; jump++) {
			temp = temp->next;
		}
		Node* n = new Node(data);
		n->next = temp->next;;
		temp->next = n;
	}

	int recursiveSearch(int key) {
		int abc = searchHelper(head, key);
		return abc;
	}

	void pop_front() {
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}

	void pop_back() {
		Node* temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		delete tail;
		temp->next = NULL;
		tail = temp;
	}

	void delete_pos(int pos) {
		Node* temp = head;
		for (int jump = 1; jump < pos-1; jump++) {
			temp = temp->next;
		}
		Node* temp1 = temp->next;
		temp->next = temp1->next;
		temp1->next = NULL;
		delete temp1;
	}

	void print_list() {
		Node* head = begin();
		while (head != NULL) {
			cout << head->get_data();
			head = head->next;
			if (head != NULL) {
				cout << " => ";
			}
			else
				cout << endl;
		}
	}


	~List() {
		if (head != NULL) {
			delete head;
		}
	}

};