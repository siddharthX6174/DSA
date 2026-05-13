#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> colorGrid(int nvals, int mvals, vector<vector<int>>& srces) {
		vector<vector<int>> grids(nvals, vector<int>(mvals, 0));
		vector<vector<int>> dists(nvals, vector<int>(mvals, -1));
		queue<pair<int, int>> queus;
		for (const auto& sours : srces) {
			int rowss = sours[0];
			int colss = sours[1];
			int color = sours[2];
			grids[rowss][colss] = color;
			dists[rowss][colss] = 0;
			queus.push({rowss, colss});
		}
		int drowr[] = {0, 0, 1, -1};
		int dcolc[] = {1, -1, 0, 0};
		while (!queus.empty()) {
			pair<int, int> front = queus.front();
			queus.pop();
			int rowss = front.first;
			int colss = front.second;
			for (int idxxx = 0; idxxx < 4; ++idxxx) {
				int nextr = rowss + drowr[idxxx];
				int nextc = colss + dcolc[idxxx];
				if (nextr >= 0 && nextr < nvals && nextc >= 0 && nextc < mvals) {
					if (dists[nextr][nextc] == -1) {
						dists[nextr][nextc] = dists[rowss][colss] + 1;
						grids[nextr][nextc] = grids[rowss][colss];
						queus.push({nextr, nextc});
					} else if (dists[nextr][nextc] == dists[rowss][colss] + 1) {
						grids[nextr][nextc] = max(grids[nextr][nextc], grids[rowss][colss]);
					}
				}
			}
		}
		return grids;
	}
};