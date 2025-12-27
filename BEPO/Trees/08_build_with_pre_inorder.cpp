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



// Tree from inorder and preorder Traversal
int i = 0;
node* buildTreeFromPreAndIn(int* pre, int* in, int s, int e) {

	if (s > e) {
		return nullptr;
	}


	node* root = new node(pre[i]);
	int index = -1;
	for (int x = s; x <= e; x++) {
		if (in[x] == pre[i]) {
			index = x;
			break;
		}
	}
	i++;
	root->left = buildTreeFromPreAndIn(pre, in, s, index - 1);
	root->right = buildTreeFromPreAndIn(pre, in, index + 1, e);
	return root;
}

int main() {
	int pre[] = {1, 2, 3, 4, 5, 7, 6};
	int in[] = {3, 2, 4, 1, 7, 5, 6};

	node* root = buildTreeFromPreAndIn(pre, in, 0, 6);
}