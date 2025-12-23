class Solution {
public:
    vector<vector<string>> ans;

    bool canplace(vector<string>&grid, int row, int col, int n) {
        // chekc in row
        for (int i = 0; i < n; i++) {
            if (grid[i][col] == 'Q') return false;
        }
        // check col
        for (int i = 0; i < n; i++) {
            if (grid[row][i] == 'Q') return false;
        }
        // top left
        int i = row, j = col;
        while (i >= 0 and j >= 0) {
            if (grid[i][j] == 'Q') return false;
            i--;
            j--;
        }
        // top right
        i = row, j = col;
        while (i >= 0 and j < n) {
            if (grid[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    bool solve(int row, int n, vector<string>& grid) {
        if (row == n) {
            ans.push_back(grid);
            return false;
        }

        // task
        for (int col = 0; col < n; col++) {
            if (canplace(grid, row, col, n) == 1) {
                grid[row][col] = 'Q';
                bool smallproblem = solve(row + 1, n, grid);
                if (smallproblem == 1) {
                    return true;
                }
                grid[row][col] = '.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        solve(0, n, grid); // row , n
        return ans;
    }
};