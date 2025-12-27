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

// input type format 1
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


void leftView(node* root, int level, int &mvl) {

	if (root == nullptr) {
		return;
	}

	if (level > mvl) {
		cout << root->data << " ";
		mvl = level;
	}

	leftView(root->left, level + 1, mvl);
	leftView(root->right, level + 1, mvl);
}


int main() {
	node* root = buildtree();
	int mvl = -1;
	leftView(root, 0, mvl);
}