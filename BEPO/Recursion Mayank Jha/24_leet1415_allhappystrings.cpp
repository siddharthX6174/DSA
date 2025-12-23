class Solution {
public:
    vector<string> all;

    void solve(int i, int n, string& curr) {
        if (i == n) {
            all.push_back(curr);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (!curr.empty() && curr.back() == ch)
                continue; // happy string condition

            curr.push_back(ch);
            solve(i + 1, n, curr);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr;
        solve(0, n, curr);

        if (k > all.size())
            return "";

        return all[k - 1]; // 1-based to 0-based
    }
};
