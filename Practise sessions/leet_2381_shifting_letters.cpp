class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();

        vector<int> diff(n, 0);

        // step-1 : build the difference array
        for (auto &query : shifts) {
            int L   = query[0];
            int R   = query[1];
            int dir = query[2];

            int x = {};
            if (dir == 0) {
                x = -1;
            } else {
                x = +1;
            }

            diff[L] += x;
            if (R + 1 < n) {
                diff[R + 1] -= x;
            }
        }

        // step-2 : Find the cummalative sum to find the resultant change/shift in the index
        for (int i{1}; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        // Now apply the shift change
        for (int i{0}; i < n; i++) {
            int shift = diff[i] % 26;

            if (shift < 0) {
                shift += 26;
            }

            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }
        return s;

    }
};