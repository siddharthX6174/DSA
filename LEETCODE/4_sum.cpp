class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for (int m{}; m < n - 3; m++) {
            if ( m > 0 and nums[m] == nums[m - 1]) continue;

            for (int k = m + 1; k < n - 2; k++) {
                if ( k > m + 1 and nums[k] == nums[k - 1]) continue;

                int i = k + 1, j = n - 1;
                while (i < j) {
                    long long int sum = (long long)nums[m] + nums[k] + nums[i] + nums[j];

                    if (sum == target) {
                        result.push_back({nums[m] , nums[k] , nums[i] , nums[j]});
                        ++i;
                        j--;

                        while (i < j and nums[i] == nums[i - 1]) ++i;
                        while (i < j and nums[j] == nums[j + 1]) --j;
                    }
                    else if (sum < target) {
                        ++i;
                    }
                    else {
                        j--;
                    }
                }
            }
        }
        return result;
    }
};