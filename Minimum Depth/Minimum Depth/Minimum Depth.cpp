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

int DepthFinder(Node* root, int &depth, bool depth_check) {
	if (root == NULL)
		return depth;
	int depth_left = DepthFinder(root->left, depth, depth_check) + 1;
	int depth_right = DepthFinder(root->right, depth, depth_check) + 1;
	depth = min(depth_left, depth_right);
	return depth;
}

int minDepth(Node* root) {
	int depth = 0;
	depth = DepthFinder(root, depth, false);
	return depth;
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
	cout << minDepth(root) << " is the Depth";
}