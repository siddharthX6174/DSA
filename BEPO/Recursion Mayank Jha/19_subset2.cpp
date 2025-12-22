class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void solve(int index, vector<int>&nums) {
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            // skip element of duplicate
            if (i != index and nums[i] == nums[i - 1]) continue;
            // take
            curr.push_back(nums[i]);
            solve(i + 1, nums);
            curr.pop_back();
        }

        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());

        solve(0, nums);
        return ans;
    }
};