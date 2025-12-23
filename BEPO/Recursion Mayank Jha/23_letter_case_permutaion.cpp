class Solution {
public:
    vector<string> ans;
    void solve(int i, string& s) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        // task
        if (isalpha(s[i])) {
            // first take the original
            solve(i + 1, s);
            // take the toggled character
            s[i] ^= 32;
            solve(i + 1, s);
            s[i] ^= 32; // backtrack or maintain the original state
        } else {
            // it is a digit just move forward
            solve(i + 1, s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(0, s);
        return ans;
    }
};