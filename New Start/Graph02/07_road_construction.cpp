#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	// Track forbidden edges
	vector<unordered_set<int>> forbidden(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		forbidden[x].insert(y);
		forbidden[y].insert(x);
	}

	int center = -1;
	// Find the best center (city with minimum forbidden connections)
	for (int i = 1; i <= n; i++) {
		if ((int)forbidden[i].size() < n - 1) {
			center = i;
			break;
		}
	}

	vector<pair<int, int>> roads;
	vector<int> connected;

	// Connect all possible cities to center
	for (int i = 1; i <= n; i++) {
		if (i != center && forbidden[center].find(i) == forbidden[center].end()) {
			roads.push_back({center, i});
			connected.push_back(i);
		}
	}

	// Connect remaining cities to any already-connected city
	for (int i = 1; i <= n; i++) {
		if (i != center && forbidden[center].find(i) != forbidden[center].end()) {
			// City i cannot connect to center, find another connection
			for (int j : connected) {
				if (forbidden[i].find(j) == forbidden[i].end()) {
					roads.push_back({i, j});
					break;
				}
			}
		}
	}

	// Print results
	cout << roads.size() << endl;
	for (auto& road : roads) {
		cout << road.first << " " << road.second << endl;
	}

	return 0;
}