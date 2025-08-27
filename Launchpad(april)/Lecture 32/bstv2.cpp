# include <iostream>
using namespace std;
# include <climits>

template<typename T>
class TreeNodeBst {
public:
	T val;
	TreeNodeBst* left;
	TreeNodeBst* right;

	//constructor
	TreeNodeBst(int value) {
		val = value;
		left = nullptr;
		right = nullptr;
	}
};

// insert in bst
template<typename T>
TreeNodeBst<int>* InsertinBst(TreeNodeBst<int>* root, int value) {
	if (root == nullptr) {
		root = new TreeNodeBst<int>(value);
		return root;
	}
	// 10(root) > 5(new value)
	if (root->val > value) {
		root->left = InsertinBst(root->left, value);
	}
	if (root->val < value) {
		root->right = InsertinBst(root->right, value);
	}
	return root;
}

// builder for insertion
TreeNodeBst<int>* buildbst() {
	int x;
	cin >> x;

	if (x == -1) return nullptr;

	TreeNodeBst<int>* root = nullptr;

	while (x != -1) {
		root = InsertinBst(root, x);
		cin >> x;
	}
	return root;
}

// searching in bst
template <typename T>
bool searchinbst(TreeNodeBst<int>* root, T target) {
	if (root == nullptr) {
		return false;
	}
	if (root->val == target) {
		return true;
	}

	if (root->val < target) {
		return searchinbst(root->right, target);
	} else {
		return searchinbst(root->left, target);
	}
}

// is it bst greatest version
template<typename T>
bool isbst(TreeNodeBst<int>* root, int mini = INT_MIN, int maxi = INT_MAX) {
	if (root == nullptr) {
		return true;
	}
	// ky mera current node bst ki property hhold krta haii
	bool op1 = 0;
	if (root->val )
	}


int main() {

}