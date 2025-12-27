#include<bits/stdc++.h>
using namespace std;

class Pair1 {
public:
	int height;
	bool isbalanced;
};

Pair1 p;

Pair1 IsHeightBalanced(TreeNode* root) {

	if (root == nullptr) {
		p.height = 0;
		p.isbalanced = true;
		return p;
	}


	//left , right
	Pair1 lst = IsHeightBalanced(root->left);
	Pair1 rst = IsHeightBalanced(root->right);

	// task
	p.height = max(lst.height, rst.height) + 1;

	if (lst.isbalanced == true and rst.isbalanced == true and abs(lst.height - rst.height) <= 1) {
		p.isbalanced = true;
	} else {
		p.isbalanced = false;
	}

	return p;
}