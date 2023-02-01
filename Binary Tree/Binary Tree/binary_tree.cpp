#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
	int data;
	Node* right;
	Node* left;

	Node(int d) {
		data = d;
		left = right = NULL;
	}

};

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

void printPreorder(Node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder(Node* root) {
	if (root == NULL)
		return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

void printPostOrder(Node* root) {
	if (root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->data << " ";
}

void printLevelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		Node* temp = q.front();
		if (temp == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else
		{
			q.pop();
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
	return;
}

int main() {
	Node* root = buildtree();
	cout << endl;
	cout << "Preorder is " << endl;
	printPreorder(root);
	
	cout << endl;
	cout << "Inorder is " << endl;
	printInorder(root);

	cout << endl;
	cout << "Postorder is " << endl;
	printPostOrder(root);

	cout << endl;
	cout << "LevelOrder is " << endl;
	printLevelOrder(root);
}