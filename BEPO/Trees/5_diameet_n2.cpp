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



// optimized diamter
class Pair1 {
public:
	int height;
	int diameter;
	Pair1() {
		height = 0;
		diameter = 0;
	}
	Pair1(int height, int diameter) {
		this->height = height;
		this->diameter = diameter;
	}
};

Pair1 p; // making an object
// using post order traversal
Pair1 fastDiameter(TreeNode* root) {
	if (root == nullptr) {
		p.height = 0;
		p.diameter = 0;
		return p;
	}

	// left call and right call
	Pair1 left_sub_tree = fastDiameter(root->left);
	Pair1 right_sub_tree = fastDiameter(root->right);

	// task

	p.height = max(left_sub_tree.height, right_sub_tree.height) + 1;

	int op1 = left_sub_tree.diameter;
	int op2 = right_sub_tree.diameter;
	int op3 = (left_sub_tree.height + right_sub_tree.height);
	p.diameter = (max(max(op1, op2), op3));

	return p;
}

int main() {
	TreeNode* root = buildtree();

	Preorder(root);
	cout << "\n";

	cout << fastDiameter(root).diameter ;


}