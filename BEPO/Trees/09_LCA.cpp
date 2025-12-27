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

// lowest common ancestor
node* LowestCommonAncestor(node* root, node* p, node* q) {

	if (root == nullptr) {
		return nullptr;
	}

	// task
	if (root->val == p->val or root->val == q->val) {
		return root;
	}
	// left and right call
	node* l = LowestCommonAncestor(root->left, p, q);
	node* r = LowestCommonAncestor(root->right, p, q);

	if (l != nullptr and r != nullptr) {
		return root;
	} else if (l != nullptr and r == nullptr) {
		return l;
	} else {
		return r;
	}
}

