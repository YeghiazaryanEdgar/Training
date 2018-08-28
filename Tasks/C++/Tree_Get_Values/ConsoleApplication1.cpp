#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int value) {
	Node* n = new Node;

	n->data = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void getNodeValue(Node *n) {
	if (n == NULL) return;
	cout << n->data << ", ";
	getNodeValue(n->left);
	getNodeValue(n->right);
}

int main() {
   
	Node* root = createNode(1);

	root->left = createNode(32);
	root->right = createNode(33);

	root->left->left = createNode(14);
	root->right->left = createNode(25);
	root->right->right = createNode(56);

	root->right->left->right = createNode(17);
	root->right->right->right = createNode(28);

	root->right->left->right->left = createNode(49);

	getNodeValue(root);

	return 0;
}

