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
