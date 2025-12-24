class Solution {
public:
    int maxgold = 0;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = { -1, 0, 1, 0};

    void solve(vector<vector<int>>& grid, int i, int j, int gold) {
        maxgold = max(maxgold, gold);

        int curr = grid[i][j]; // store the current grid state
        grid[i][j] = 0;  // mark visited

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < grid.size() &&
                    y >= 0 && y < grid[0].size() &&
                    grid[x][y] != 0) {
                solve(grid, x, y, gold + grid[x][y]);
            }
        }

        grid[i][j] = curr;  // backtrack or revert the current state of grid to oriin=ginal
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    solve(grid, i, j, grid[i][j]);
                }
            }
        }
        return maxgold;
    }
};
