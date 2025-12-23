class Solution {
public:
    int ans{};

    void solve(int idx, int sum, int target, vector<int>& nums) {
        if (idx == nums.size()) {
            if (sum == target) ans++;
            return;
        }

        // choose +
        solve(idx + 1, sum + nums[idx], target, nums);

        // choose -
        solve(idx + 1, sum - nums[idx], target, nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0, 0, target, nums);
        return ans;
    }
};
