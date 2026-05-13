#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int pathLen, vector<vector<int>>&adjLs, int &maxLen, unordered_map<int, int>& visited) {
	visited[u] = pathLen;

	for (int v : adjLs[u]) {
		if (visited.count(v)) {
			maxLen = max(maxLen, pathLen - visited[v] + 1);
		} else {
			dfs(v, pathLen + 1, adjLs, maxLen, visited);
		}
	}
}


int main() {
	int n;
	cin >> n;

	vector<int> edges(n);
	for (int i = 0; i < n; i++) {
		cin >> edges[i];
	}

	vector<vector<int>> adjLs(n);

	for (int i = 0; i < n; i++) {
		if (edges[i] == -1) continue;
		adjLs[i].push_back(edges[i]);
	}

	int maxLen = 0;
	unordered_map<int, int> visited;

	for (int u = 0; u < n; u++) {
		if (!visited.count(u)) {
			dfs(u, 0, adjLs, maxLen, visited);
		}
	}

	if (maxLen == 0) {
		cout << -1 << endl;
	}
	else {
		cout << maxLen << endl;
	}
	return 0;
}