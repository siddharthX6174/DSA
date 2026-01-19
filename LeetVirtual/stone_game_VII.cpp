class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& stones, int sum) {
        if (i == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int op1 = (sum - stones[i]) - solve(i + 1, j, stones, sum - stones[i]);
        int op2 = (sum - stones[j]) - solve(i, j - 1, stones, sum - stones[j]);

        return dp[i][j] = max(op1, op2);
    }
    int stoneGameVII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            sum += stones[i];
        }

        dp.resize(n + 3, vector<int>(n + 4, -1));

        int val = solve(0, n - 1, stones, sum);
        return val;
    }
};