# include <iostream>
# include <vector>
# include <map>
# include <utility>
using namespace std;

void dfs(TreeNode<int>*root, map<int, int>&mp, int coulumn_no) {

	if (root == nullptr) {
		return;
	}

	// Insertion : Preorder is must here.
	// because for every column we want to insert the first element
	mp.insert({coulumn_no, root->val});

	dfs(root->left, mp, coulumn_no - 1);
	dfs(root->right, mp, coulumn_no + 1);
}

vector<int>Topview(TreeNode<int>* root) {
	vector<int> ans;
	// map<column_bo, value> mp;
	map<int, int>mp;
	dfs(root, mp, 0);

	for (pair<int, int> x : mp) {
		ans.push_back(x.second());
	}

	return ans;

}



int main() {
	TreeNode<int>* root = BuildTree();
	bfs2(root);

	cout << endl << "------------------------------------" << endl;

	vector<int> ans = Topview(root);
	// print karo
}