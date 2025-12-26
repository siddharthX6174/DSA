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
    vector<vector<int>> ans;
    vector<int>current;
    void solve(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr) {
            return;
        }

        sum += root->val;
        current.push_back(root->val);

        // check is it leaf ?
        if (root->left == nullptr and root->right == nullptr) {
            if (sum == targetSum) {
                ans.push_back(current);
            }
        }

        solve(root->left, sum, targetSum);
        solve(root->right, sum, targetSum);

        current.pop_back();//backtrack
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, 0, targetSum);
        return ans;
    }
};