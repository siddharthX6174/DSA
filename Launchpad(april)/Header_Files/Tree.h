/*# include <iostream>
# include "D:\C++\Launchpad(april)\Header_Files\TreeNode.h"
using namespace std;

TreeNode<int>BuildTree() {

	int x;
	cin >> x;

	if (x == -1) {
		return nullptr;
	} else {
		TreeNode<int>* r = new TreeNode<int>(x);
		r->left = BuildTree();
		r->right = BuildTree();
		return r;
	}
}

void Preorder(TreeNode<int> * root) {
	if (root == nullptr) {
		return;
	}
	cout << root->val << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(TreeNode<int> * root) {
	if (root == nullptr) {
		return;
	}
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}


void Postorder(TreeNode<int> * root) {
	if (root == nullptr) {
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->val << " ";
}*/


#pragma once
#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* BuildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		return nullptr;
	} else {
		TreeNode<int>* r = new TreeNode<int>(x);
		r->left = BuildTree();
		r->right = BuildTree();
		return r;
	}
}

void Preorder(TreeNode<int>* root) {
	if (root == nullptr) return;
	cout << root->val << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(TreeNode<int>* root) {
	if (root == nullptr) return;
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

void Postorder(TreeNode<int>* root) {
	if (root == nullptr) return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->val << " ";
}


int Height(TreeNode<int>* root) {
	if (root == nullptr) return 0;

	if LSH = Height(root->left);
	if RSH = Height(root->right);

	return max(LSH, RSH) + 1;
}


int CountNode(TreeNode<int>* root) {
	if (root == nullptr) return 0;

	int LSN = CountNode(root->left);
	int RSN = CountNode(root->right);

	return LSN + RSN + 1;
}

int SumofNodes(TreeNode<int>* root) {
	if (root == nullptr) return 0;

	int LSS = SumofNodes(root->left);
	int RSS = SumofNodes(root->right);

	return LSS + RSS + root->val;
}

//preorder traversal
void Mirror(TreeNode<int>* root) {
	if (root == nullptr) return;

	swap(root->left, root->right);
	Mirror(root->left);
	Mirror(root->right);
}