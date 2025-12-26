/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        sum += root->val;

        // check is it leaf ?
        if (root->left == nullptr and root->right == nullptr) {
            return (sum == targetSum);
        }

        bool left_subtree = solve(root->left, sum, targetSum);
        bool right_subtree = solve(root->right, sum, targetSum);

        return left_subtree or right_subtree;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, 0, targetSum);
    }
};