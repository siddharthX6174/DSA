/*#include<iostream>
#include"D:\C++\Launchpad(april)\Header_Files\Tree.h"
using namespace std;

int main() {
	TreeNode* root = BuildTree();
	Preorder(root);
	cout << endl;

	Inorder(root);
	cout << endl;

	Postorder(root);
	cout << endl;
}*/


#include <iostream>
#include "D:\C++\Launchpad(april)\Header_Files\Tree.h"
using namespace std;

int main() {
	cout << "Enter tree data (-1 for NULL): ";
	TreeNode<int>* root = BuildTree();

	cout << "Preorder: ";
	Preorder(root);
	cout << endl;

	cout << "Inorder: ";
	Inorder(root);
	cout << endl;

	cout << "Postorder: ";
	Postorder(root);
	cout << endl;

	return 0;
}
