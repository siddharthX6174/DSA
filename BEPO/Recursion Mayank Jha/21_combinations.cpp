void solve(int start, int n, int k, vector<int>& curr, vector<vector<int>>& ans) {
    if (curr.size() == k) {
        ans.push_back(curr);
        return;
    }

    for (int i = start; i <= n; i++) {
        curr.push_back(i);
        solve(i + 1, n, k, curr, ans);
        curr.pop_back();
    }
}
