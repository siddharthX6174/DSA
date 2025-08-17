#include<iostream>
#include"../Header_Files/Tree.h"
using namespace std;




int main() {

	TreeNode<int>* root = BuildTree();
	// Preorder(root);
	// cout << endl;
	// Inorder(root);
	// cout << endl;
	// Postorder(root);
	// cout << endl;
	// cout << Diameter(root) << endl;
	// Diameter2(root);
	// cout << maxi << endl;
	// cout << Diameter3(root).height << " " << Diameter3(root).diameter << endl;
	// cout << IsHeightBalanced(root).first << " " << IsHeightBalanced(root).second << endl;
	PrintAllLevel(root);
	bfs(root);
	cout << endl;
	bfs2(root);
}