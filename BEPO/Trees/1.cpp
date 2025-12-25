#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data{};
	node* left;
	node* right;

	node() {
		left = nullptr;
		right = nullptr;
	}

	node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

node* buildtree() {
	int x{};
	cin >> x;
	if (x == -1) {
		return nullptr;
	} else {
		node* temp = new node (x);
		temp->left = buildtree();
		temp->right = buildtree();
		return temp;
	}
}

// print
void Preorder(node* root) {
	if (root == nullptr) return;

	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(node* root) {
	if (root == nullptr) return;

	Preorder(root->left);
	cout << root->data << " ";
	Preorder(root->right);
}

void Postorder(node* root) {
	if (root == nullptr) return;

	Preorder(root->left);
	Preorder(root->right);
	cout << root->data << " ";
}



int main() {
	node* root = buildtree();

	cout << "Preorder: ";
	Preorder(root);
	cout << "\n";

	cout << "Inorder: ";
	Inorder(root);
	cout << "\n";

	cout << "Postorder: ";
	Postorder(root);
	cout << "\n";

	return 0;
}