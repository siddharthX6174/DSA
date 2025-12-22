class Solution {
public:
    vector<vector<int>> res;
    void solve(int start, vector<int>&nums) {
        if (start == nums.size()) {
            res.push_back(nums);
        }

        unordered_set<int>used;

        for (int end = start; end < nums.size(); end++) {
            //skip
            if (used.count(nums[end])) {
                continue;
            }

            //task
            used.insert(nums[end]);
            swap(nums[end], nums[start]);
            solve(start + 1, nums);
            swap(nums[end], nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        solve(0, nums);
        return res;
    }
};