#include <bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
private:
	map<T, multiset<T>> mp;
public:

	void addEdge(T x, T y) {
		mp[x].insert(y);
	}

	void TS_bfs() {
		map<T, int> indegree;

		// Initialize indegree for all nodes
		for (auto &x : mp) {
			indegree[x.first] = 0;
		}

		// Calculate indegree of each node
		for (auto &x : mp) {
			for (auto nbr : x.second) {
				indegree[nbr]++;
			}
		}

		queue<T> q;

		// Push all nodes with indegree 0
		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}

		// Kahn's Algorithm
		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << " ";

			for (auto nbr : mp[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m ;

	graph<int> gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y);
	}

	gr.TS_bfs();

	return 0;
}
