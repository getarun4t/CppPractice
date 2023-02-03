#include <iostream>
#include<vector>
using namespace std;

struct Node {
    int key;
    Node* left, * right;
public:
	Node(int d) {
		key = d;
		left = right = NULL;
	}
};

vector<int> printKthLevelRecurser(Node* root, int k, int c, vector<int> &v) {
	if (root == NULL) {
		return v;
	}
	if (c == k){
		v.push_back(root->key);
		return v;
	}
	printKthLevelRecurser(root->left, k, c+1, v);
	printKthLevelRecurser(root->right, k, c+1, v);
	return v;
}

vector<int> printKthLevel(Node* root, int k) {
    // your code goes here
	int c = 0;
	vector<int> items;
	items = printKthLevelRecurser(root, k, c, items);
	return items;
}

Node* buildtree() {
	int d;
	cout << "Enter next elements: ";
	cin >> d;
	if (d == -1)
		return NULL;
	
	Node* n = new Node(d);
	n->left = buildtree();
	n->right = buildtree();
	return n;
}

int main() {
	Node* root = buildtree();
	vector<int> c = printKthLevel(root, 1);
	for (auto q : c) {
		cout << endl;
		cout << q << " ";
	}
}