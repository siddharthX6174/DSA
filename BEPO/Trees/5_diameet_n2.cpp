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

// O(n)
int height(TreeNode* root) {

	if (root == nullptr) {
		return 0;
	}

	int lsh = height(root->left);
	int rsh = height(root->right);

	return max(lsh, rsh) + 1;
}

// O(n)  -->> overall O(n^2)
int diameter(TreeNode* root) {

	if (root == nullptr) {
		return 0;
	}

	// diameter passes through root;
	int RootDiameter = height(root->left) + height(root->right);
	// diamter lies in left subtree
	int lsd = diameter(root->left);
	// diamter lies in right subtree;
	int rsd = diameter(root->right);

	return max(max(lsd, rsd), RootDiameter);
}

int main() {
	TreeNode* root = buildtree();

	Preorder(root);
	cout << "\n";


}