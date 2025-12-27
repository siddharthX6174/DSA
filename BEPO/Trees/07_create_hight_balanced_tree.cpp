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

// print
void Preorder(node* root) {
	if (root == nullptr) return;

	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}


node* createHBT(int* a, int s, int e) {

	if (s > e) {
		return nullptr;
	}


	int mid = (s + e) / 2;

	node* root = new node(a[mid]);

	//left
	root->left = createHBT(a, s, mid - 1);
	//right
	root->right = createHBT(a, mid + 1, e);

	return root;

}

int main() {
	int a[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	node* root = createHBT(a, 0, 10);

	Preorder(root);


}