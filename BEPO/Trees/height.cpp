#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

TreeNode* buildtree() {
	int x;
	cin >> x;
	if (x == -1) {
		return nullptr;
	} else {
		TreeNode* temp = new TreeNode (x);
		temp->left = buildtree();
		temp->right = buildtree();
		return temp;
	}
}

// preorderd
void Preorder(TreeNode* root) {
	if (root == nullptr) {
		return;
	}

	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

// heighta
int height(TreeNode* root) {

	if (root == nullptr) {
		return 0;
	}

	int lsh = height(root->left);
	int rsh = height(root->right);

	return max(lsh, rsh) + 1;
}


void mirror(TreeNode* temp) {
	if (temp == nullptr) {
		return;
	}
	// task // swap adress
	swap(temp->left, temp->right);
	mirror(temp->left);
	mirror(temp->right);
}



int main() {
	TreeNode* root = buildtree();

	Preorder(root);
	cout << "\n";

	cout << height(root) << "\n";

	mirror(root);

	Preorder(root);

	mirror(root);

}