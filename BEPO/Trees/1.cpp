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


// funcitons
//count nodes of a tree
int CountNodes(node* root) {

	if (root == nullptr) {
		return 0;
	}

	int left_Subtree = CountNodes(root->left);
	int right_Subtree = CountNodes(root->right);

	int ans = left_Subtree + right_Subtree + 1;
	return ans;
}

// sum of nodes
int sum_nodes(node* root) {
	if (root == nullptr) {
		return 0;
	}

	int left_Subtree = sum_nodes(root->left);
	int right_Subtree = sum_nodes(root->right);
	int ans = left_Subtree + right_Subtree + root->data;
	return ans;
}


// height, mirror , diameter



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

	cout << "number of nodes : " << CountNodes(root) << "\n";
	cout << "sum of nodes : " << sum_nodes(root) << "\n";

	return 0;
}