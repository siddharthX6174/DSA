class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& curr, vector<int>& nums) {
        if (curr.size() >= 2) {
            ans.push_back(curr);
        }

        unordered_set<int> used; // avoid duplicates at same level

        for (int i = idx; i < nums.size(); i++) {
            // non-decreasing condition
            if (!curr.empty() && nums[i] < curr.back())
                continue;

            // avoid duplicates
            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);
            curr.push_back(nums[i]);
            solve(i + 1, curr, nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        solve(0, curr, nums);
        return ans;
    }
};
