#include <bits/stdc++.h>
using namespace std;

vector<int> h;
class graph {
	map<pair<int, int>, list<pair<int, int>>> mp;

public:

	void addEdge(int x, int y) {
		mp[ {x, h[x]}].push_back({y, h[y]});
		mp[ {y, h[y]}].push_back({x, h[x]});
	}

	int ans(int n) {
		vector<bool> good(n + 1, true);

		// Mark bad nodes
		for (auto &x : mp) {
			int node = x.first.first;
			int height = x.first.second;

			for (auto nbr : x.second) {
				if (nbr.second >= height) {
					good[node] = false;
					break;
				}
			}
		}

		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (good[i]) count++;
		}
		return count;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	h.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	graph gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y);
	}

	cout << gr.ans(n) << endl;
	return 0;
}
