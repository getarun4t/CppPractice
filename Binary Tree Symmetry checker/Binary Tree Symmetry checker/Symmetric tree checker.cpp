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



bool checkIsSymmetric(Node* left_root, Node* right_root, bool flag) {
	if ((left_root == right_root) and (left_root == NULL))
		return true;
	if ((right_root == NULL) or (left_root == NULL))
		return false;
	if (left_root->key != right_root->key) {
		flag == false;
		return false;
	}
	bool left_flag = checkIsSymmetric(left_root->left, right_root->left, true);
	bool right_flag = checkIsSymmetric(left_root->right, right_root->right, true);
	if ((left_flag == false) or (left_flag == false) ){
		return false;
	}
	return true;
}

bool isSymmetric(Node* root) {
	return checkIsSymmetric(root->left, root->right, true);
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
	cout << isSymmetric(root) << " is the result";
}