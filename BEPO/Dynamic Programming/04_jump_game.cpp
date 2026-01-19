#include <bits/stdc++.h>
using namespace std;

const int N;

class Solution {
public:
    bool solve(int i, int n, vector<int>& nums) {
        if (i >= n) {
            return true;
        }
        if (nums[i] == 0) return false;

        int maxjump = nums[i];
        for (int jump = 1; jump <= maxjump; jump++) {
            if (solve(i + jump, n, nums)) {
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    N = n - 1;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    bool ans = obj.canJump(nums);   // function call

    if (ans) cout << "true";
    else cout << "false";

    return 0;
}
