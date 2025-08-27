# include <iostream>
using namespace std;

// node create
template<typename T>
class TreeNode {
public:
	T val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};

// build tree
TreeNode<int>* BuildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		return nullptr;
	}

	TreeNode<int>* temp = new TreeNode<int>(x);
	temp->left = BuildTree();
	temp->right = BuildTree();
	return temp;
}


// Tree Traversal and value

void Preorder(TreeNode<int>* root) {
	if (root == nullptr) {
		return;
	}

	cout << root->val << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(TreeNode<int>* root) {
	if (root == nullptr) {
		return;
	}

	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

void Postorder(TreeNode<int>* root) {
	if (root == nullptr) {
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->val << " ";
}

//Computation : n
int Height(TreeNode<int>*root) {
	if (root == NULL) {
		return 0;
	}

	int LSH = Height(root->left);
	int RSH = Height(root->right);

	return max(LSH, RSH) + 1;
}


// count the total number of nodes in a tree
int CountNodes(TreeNode<int>* root) {
	if (root == nullptr) {
		return 0;
	}

	int LSN = CountNodes(root->left);
	int RSN = CountNodes(root->right);
	return LSN + RSN + 1;
}

//calculat ethe sum of nodes
int sumofnodes(TreeNode<int>* root) {
	if (root == nullptr) {
		return 0;
	}

	int LSN = sumofnodes(root->left);   // left subtree sum
	int RSN = sumofnodes(root->right);  // right subtree sum

	return LSN + RSN + root->val;       // total sum
}

// make the mirror image of the tree
void Mirror(TreeNode<int>*root) {

	if (root == NULL) {
		return;
	}

	Mirror(root->left);
	Mirror(root->right);
	swap(root->left, root->right);
}


// lowest common ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == nullptr) {
		return nullptr;
	}

	if (root == p || root == q) {
		return root;
	}

	TreeNode* l = lowestCommonAncestor(root->left, p, q);
	TreeNode* r = lowestCommonAncestor(root->right, p, q);

	if (l != nullptr and r != nullptr) {
		return root;
	}
	if (l != nullptr and r == nullptr) {
		return l;
	}
	if (l == nullptr and r != nullptr) {
		return r;
	}
	return;
}


// diameter problem
/*
 int maxi = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }

        int LSH = height(root->left);
        int RSH = height(root->right);

        maxi = max(maxi, LSH+RSH);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxi;

    }

*/
// optimized ans
/*
int maxi=0; // dia

int height(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int lSH = height(root->left);
    int RSH = height(root->right);
    // update the dia maeter
    maxi = max(maxi, lSH + RSH);

    // return the current heiht of the subtree
    return 1 + max(lSH, RSH);
}
int diameterOfBinaryTree(TreeNode* root) {
    height(root);
    return maxi;
}

*/
















int main() {
	cout << "Enter tree nodes in Preorder (-1 for NULL):\n";
	TreeNode<int>* root = BuildTree();

	cout << "\nPreorder: ";
	Preorder(root);

	cout << "\nInorder: ";
	Inorder(root);

	cout << "\nPostorder: ";
	Postorder(root);

	return 0;
}