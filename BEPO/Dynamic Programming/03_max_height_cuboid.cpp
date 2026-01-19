class Solution {
public:
    bool canPlace(vector<int>& a, vector<int>& b) {
        return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
    }

    int solve(int n, vector<vector<int>>& cuboids) {
        vector<int> curr(n + 1, 0), next(n + 1, 0);

        for (int currIdx = n - 1; currIdx >= 0; currIdx--) {
            for (int prev = currIdx - 1; prev >= -1; prev--) {
                int take = 0;

                if (prev == -1 || canPlace(cuboids[prev], cuboids[currIdx])) {
                    take = cuboids[currIdx][2] + next[currIdx + 1];
                }

                int notTake = next[prev + 1];

                curr[prev + 1] = max(take, notTake);
            }
            next = curr;
        }

        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: sort each cuboid
        for (auto &c : cuboids) {
            sort(c.begin(), c.end());
        }

        // Step 2: sort all cuboids
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);
    }
};
