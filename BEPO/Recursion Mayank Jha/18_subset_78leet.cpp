class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i, int n, vector<int>&current, vector<int>&nums) {

        // stoping
        if (i == n) {
            ans.push_back(current);
            return;
        }

        // taking a index
        current.push_back(nums[i]);
        solve(i + 1, n, current, nums);

        // backtrack
        current.pop_back();
        // nahi liya main
        solve(i + 1, n, current, nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>current;
        solve(0, nums.size(), current, nums);
        return ans;
    }
};