#include<iostream>
using namespace std;

template<typename T>
class TreeNode {
public:
	T val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(T val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};