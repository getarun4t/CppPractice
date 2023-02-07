#include<iostream>
#include <vector>

using namespace std;

class Node {
public:
	int key;
	Node* left;
	Node* right;

	Node(int key) {
		this->key = key;
		left = right = NULL;
	}
};

Node* insertTree(Node* root, int d) {
	if (root == NULL)
		return new Node(d);
	if (root->key > d)
		root->left = insertTree(root->left, d);
	else
		root->right = insertTree(root->right, d);
	return root;
}

bool searchTree(Node* root, int d) {
	if (root == NULL)
		return false;
	if (root->key == d)
		return true;
	else if (root->key > d)
		return searchTree(root->left, d);
	else
		return searchTree(root->right, d);
}

Node* nextInorder(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

Node* deleteNode(Node* root, int d) {
	if (root == NULL)
		return NULL;
	else if (d < root->key)
		root->left = deleteNode(root->left, d);
	else if (d > root->key)
		root->right = deleteNode(root->right, d);
	else {
		if ((root->right == NULL) and (root->left == NULL)) {
			delete root;
			root = NULL;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else {
			Node* temp = nextInorder(root->right);
			root->key = temp->key;
			root->right = deleteNode (root->right, temp->key);

		}
	}
	return root;
}

void printInorder(Node* root) {
	if (root == NULL)
		return;
	printInorder(root->left);
	cout << root->key << " ";
	printInorder(root->right);
}

int main() {
	vector<int> v = { 9,2,8,5,7,3,4,1,6 };
	Node* root = NULL;
	for (auto k : v)
		root=insertTree(root, k);
	printInorder(root);
	cout << endl;
	if (searchTree(root, 9)) { 
		cout << "present" ;
		cout << endl;
		root = deleteNode(root, 9);
	}
	else cout << "absent";
	printInorder(root);
}