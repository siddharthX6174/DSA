class Solution {
public:
    vector<string> ans;
    void solve(int n, string& current) {
        if (current.size() == n) {
            ans.push_back(current);
            return;
        }

        // choose 1
        current.push_back('1');
        solve(n, current);

        // backtrack
        current.pop_back();

        // choose 0 if preveios is not 0
        if (current.empty() or current.back() != '0') {
            current.push_back('0');
            solve(n, current);
            current.pop_back();
        }

        return;
    }
    vector<string> validStrings(int n) {
        string current;
        solve(n, current);
        return ans;
    }
};