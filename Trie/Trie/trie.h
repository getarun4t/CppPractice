#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Node {
public:
	char data;
	unordered_map<char, Node*> map;
	bool isTerminal;
	Node(char data) {
		this->data = data;
		this->isTerminal = false;
	}
};

class Trie {
	Node* root;
public:
	Trie() {
		Node* root = new Node('\0');
	}

	void insert(string data) {
		Node* temp = root;
		for(char d:data){
			if (temp->map.count(d)==0) {
				Node* n = new Node(d);
				temp->map[d] = n;
			}
			temp = temp->map[d];
		}
		temp->isTerminal = true;
	}

	bool Search(string data) {
		Node* temp = root;
		for (char d : data) {
			if (temp->map.count(d) == 0)
				return false;
		}
	}

};