#include<vector>
class Solution {
public:
    vector<int>a;
    vector<vector<int>> ans;
    vector<int> current;
    void solve(int idx, int sum, int target, int size) {

        if (sum > target) return;
        if (current.size() > size) return;

        if (current.size() == size and sum == target) {
            ans.push_back(current);
            return;
        }

        for (int i = idx; i < a.size(); i++) {
            // taking it
            current.push_back(a[i]);
            sum += a[i];
            solve(i + 1, sum, target, size);

            // backtrackkk
            sum -= a[i];
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) { // n= target, k=size of subset
        for (int i = 1; i <= 9; i++) {
            a.push_back(i);
        }
        int sum{};
        solve(0, sum, n, k);
        return ans;
    }
};