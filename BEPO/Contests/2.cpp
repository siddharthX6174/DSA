class Solution {
public:

    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long windowSum = 0;
        int left = 0;
        int ans = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            int x = nums[right];
            freq[x]++;
            if (freq[x] == 1) {
                windowSum += x;
            }
            // shrink the window now
            while (windowSum >= k) {
                ans = min(ans, right - left + 1);
                int y = nums[left];
                freq[y]--;
                if (freq[y] == 0) {
                    windowSum -= y;
                }
                left++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
}; ©leetcode