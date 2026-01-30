using namespace std;
#include<algorithm>
#include<vector>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // reverse (n-k) elements
        reverse(nums.begin() + k, nums.end());
        // reverse entire array
        reverse(nums.begin(), nums.end());
    }
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> toRotate;
        for (int x : nums) {
            if (x >= 0) {
                toRotate.push_back(x);
            }
        }
        if (!toRotate.empty()) {
            rotate(toRotate, k);
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            // positive element
            if (nums[i] >= 0) {
                nums[i] = toRotate[j];
                j++;
            }
            // negative element
        }
        return nums;
    }
};