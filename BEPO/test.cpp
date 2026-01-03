#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long countWays = 0;
	int n;
	vector<vector<int>> grid;
	const int MOD = 1e9 + 7;

	void solve(int row, int col) {
		// if all rows are filled
		if (row == n) {
			countWays = (countWays + 1) % MOD;
			return;
		}

		// move to next row
		if (col == 3) {
			solve(row + 1, 0);
			return;
		}

		// try all 3 colors
		for (int color = 0; color < 3; color++) {

			// check left cell
			if (col > 0 && grid[row][col - 1] == color)
				continue;

			// check upper cell
			if (row > 0 && grid[row - 1][col] == color)
				continue;

			grid[row][col] = color;     // place color
			solve(row, col + 1);        // recurse
			grid[row][col] = -1;        // backtrack
		}
	}

	long long numOfWays(int n) {
		this->n = n;
		grid.assign(n, vector<int>(3, -1));
		solve(0, 0);
		return countWays;
	}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	cout << sol.numOfWays(n) << endl;

	return 0;
}
