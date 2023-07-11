#pragma once

#include<iostream>

using namespace std;

template <typename T>
class Node {
public:
	T val;
	Node<T>* next;
	
	Node() = default;
};

template <typename T> class LinkedList {
	Node<T>* head;
public:
	LinkedList() {
		head = new Node<T>;
		head = nullptr;
	}

	void push_back(T val) {
		if (head == nullptr) {
			Node<T>* temp = new Node<T>;
			temp->val = val;
			temp->next = nullptr;
			head = temp;
			return;
		}
		Node<T>* temp = head;
		while (1) {
			if (temp->next == nullptr)
				break;
			temp = temp->next;
		}
		Node<T>* newN = new Node<T>;
		newN->val = val;
		newN->next = nullptr;
		temp->next = newN;
		head = temp;
	}

	void push_front(T val) {
		Node<T>* temp = new Node<T>;
		temp->val = val;
		temp->next = head;
		head = temp;
	}

	void print_all() {
		Node<T>* temp = head;
		while (1) {
			cout << temp->val << endl;
			if (temp->next == nullptr)
				break;	
			temp = temp->next;
		}
	}
};