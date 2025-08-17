#include<iostream>
#include"../Header_Files/Tree.h"
using namespace std;


int main() {

	TreeNode<int>* root = BuildTree();
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;


}