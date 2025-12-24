class Solution {
public:
    int ans{};

    void solve(int i, int n, unordered_set<int>& st) {
        if (i == n) {
            ans++;
            return;
        }

        for (int digit = 0; digit <= 9; digit++) {

            // no leading zero
            if (i == 0 && digit == 0) continue;

            // skip duplicates
            if (st.count(digit)) continue;

            st.insert(digit);
            solve(i + 1, n, st);
            st.erase(digit);  // backtrack
        }
    }

    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int total = 1;  // count number 0

        for (int len = 1; len <= n; len++) {
            ans = 0;
            unordered_set<int> st;
            solve(0, len, st);
            total += ans;
        }

        return total;
    }
};
