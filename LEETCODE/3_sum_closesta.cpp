class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minDiff = INT_MAX;
        int closest = 0;  // To store the actual closest sum

        sort(nums.begin(), nums.end());

        for (int k = 0; k < n - 2; ++k) {
            int i = k + 1;
            int j = n - 1;

            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                int diff = abs(target - sum);

                if (diff < minDiff) {
                    minDiff = diff;
                    closest = sum;
                }

                if (sum < target)
                    ++i;
                else
                    --j;
            }
        }

        return closest;
    }
};
