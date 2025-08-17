#include<iostream>
#include<algorithm>
#include<queue>
#include"../Header_Files/TreeNode.h"
using namespace std;

TreeNode<int>*BuildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		return NULL;
	} else {
		TreeNode<int>*r = new TreeNode<int>(x);
		r->left = BuildTree();
		r->right = BuildTree();
		return r;
	}
}

void Preorder(TreeNode<int>*root) {
	if (root == NULL) {
		return;
	}
	cout << root->val << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(TreeNode<int>*root) {
	if (root == NULL) {
		return;
	}
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

void Postorder(TreeNode<int>*root) {
	if (root == NULL) {
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

int CountNode(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	int LSN = CountNode(root->left);
	int RSN = CountNode(root->right);

	return LSN + RSN + 1;
}

int SumofNodes(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	int LSS = SumofNodes(root->left);
	int RSS = SumofNodes(root->right);

	return LSS + RSS + root->val;
}

void Mirror(TreeNode<int>*root) {

	if (root == NULL) {
		return;
	}

	Mirror(root->left);
	Mirror(root->right);
	swap(root->left, root->right);
}

TreeNode<int>* lca(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {

	if (root == NULL) {
		return NULL;
	}

	if (root->val == p->val or root->val == q->val) {
		return root;
	}

	TreeNode<int>* l = lca(root->left, p, q);
	TreeNode<int>* r = lca(root->right, p, q);

	if (l != NULL and r == NULL) {
		return l;
	}
	if (l == NULL and r != NULL) {
		return r;
	}

	if (l != NULL and r != NULL) {
		return root;
	}
}

//Method 1:
//Tree nodes : ~(n*n)
int Diameter(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	//When diameter passes through the root node.
	int Op1 = Height(root->left) + Height(root->right);

	//When Diameter Lies in the left subtree.
	int Op2 = Diameter(root->left);

	//When Diameter Lies in the right subtree.
	int Op3 = Diameter(root->right);

	return max({Op1, Op2, Op3});
}


//Method 2:
int maxi = 0;//I have initialised my maxi as 0 because the minimum value of the diamter can be 0 only.
//Computation : (n)
int Diameter2(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	//Post order Traversal Follow karo.
	int LSH = Diameter2(root->left);
	int RSH = Diameter2(root->right);

	maxi = max(maxi, LSH + RSH);

	int h = 1 + max(LSH, RSH);
	return h;
}

//Method 3:
class Pair {
public:
	int height;
	int diameter;

	Pair() {
		height = 0;
		diameter = 0;
	}
} x;


Pair Diameter3(TreeNode<int>*root) {

	if (root == NULL) {
		x.height = 0;
		x.diameter = 0;
		return x;
	}

	//Post Order Traversal:
	Pair LSI = Diameter3(root->left);
	Pair RSI = Diameter3(root->right);

	//Task: Calculate the height and diameter simultaneously and return the value.
	x.height = 1 + max(LSI.height, RSI.height);

	int op1 = LSI.diameter;
	int op2 = RSI.diameter;
	int op3 = (LSI.height + RSI.height);

	x.diameter = max({op1, op2, op3});

	return x;
}

//Height Balanced Tree:
pair<int, bool>y;
//y.first: Represents the height.
//y.second: Represents if the tree is height balanced or not.

pair<int, bool>IsHeightBalanced(TreeNode<int>*root) {

	if (root == NULL) {
		y.first = 0;
		y.second = 1;
		return y;
	}

	pair<int, bool>LSI = IsHeightBalanced(root->left);
	pair<int, bool>RSI = IsHeightBalanced(root->right);


	//Calculate the height and check the tree is balanced or not
	//till this point simultanoeuly.
	y.first = 1 + max(LSI.first, RSI.first);

	if (LSI.second == 1 and RSI.second == 1 and
	        abs(LSI.first - RSI.first) <= 1) {
		y.second = 1;
	} else {
		y.second = 0;
	}

	return y;
}

//Print the kth level of the tree:
void PrintKthLevel(TreeNode<int>*root, int k) {

	if (root == NULL) {
		return;
	}

	//Preorder Traversal: Work
	if (k == 1) {
		cout << root->val << " ";
		return;
	}

	//Call:
	PrintKthLevel(root->left, k - 1);
	PrintKthLevel(root->right, k - 1);
	return;
}

//Print all the nodes in all the levels of the tree:
//n*n:
void PrintAllLevel(TreeNode<int>*root) {

	int H = Height(root);

	//n Computation and n Computation
	for (int i = 1; i <= H; i++) {

		//n Computation
		PrintKthLevel(root, i);
		cout << endl;
	}

	return;
}

//Breadth First Search : Level Order Traversal:
//n Computation:

void bfs(TreeNode<int>*root) {

	queue<TreeNode<int>*>q;//Address of the node.
	q.push(root);
	while (!q.empty()) {

		TreeNode<int>*f = q.front();
		cout << f->val << " ";
		q.pop();

		if (f->left != NULL) {
			q.push(f->left);
		}

		if (f->right != NULL) {
			q.push(f->right);
		}

	}

}

vector<vector<int>>ans;

//n computation
void bfs2(TreeNode<int>*root) {
	queue<TreeNode<int>*>q;//Address of the node.
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		TreeNode<int>*f = q.front();
		q.pop();

		if (f == NULL) {
			cout << endl;
			//Current Level is finished.
			if (!q.empty()) {
				q.push(NULL);
			}

		} else {

			cout << f->val << " ";
			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}
		}
	}

}

