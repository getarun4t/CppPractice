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

int NodeSummer(Node* root, int &sum, bool flag) {
	if (root == NULL) {
		return sum;
	}
	if (!flag) {
		sum += root->key;
		flag = true;
	}
	NodeSummer(root->left, sum, false);
	NodeSummer(root->right, sum, false);
	return sum;
}

int sumBT(Node* root)
{
	int sum = 0;
	sum = NodeSummer(root, sum, false);
	return sum;
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
	cout << endl;
	cout <<  sumBT(root) << " is the Sum";
}