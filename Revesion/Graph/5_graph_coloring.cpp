#include <bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
private:
	map<T, list<T>> mp;
public:

	void addEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	void print() {
		for (auto p : mp) {
			cout << p.first << " --> ";
			for (auto x : p.second) {
				cout << x << " ";
			}
			cout << endl;
		}
	}

	bool dfs_helper(T node, T parent, map<T, int>& visited, int color) {
		visited[node] = color;

		for (auto nbr : mp[node]) {
			if (visited[nbr] == 0) {
				if (!dfs_helper(nbr, node, visited, 3 - color)) {
					return false;
				}
			}
			else if (nbr != parent && visited[nbr] == color) {
				return false;
			}
		}
		return true;
	}

	bool dfs(T src) {
		map<T, int> visited;
		for (auto x : mp) visited[x.first] = 0;

		return dfs_helper(src, -1, visited, 1);
	}
};

int main() {
	int n, m, direction;
	cin >> n >> m >> direction;

	graph<int> gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y, direction);
	}

	gr.print();
	cout << endl << endl;

	if (gr.dfs(1)) {
		cout << "Bipartite Graph" << endl;
	}
	else {
		cout << "Not Bipartite Graph" << endl;
	}

	return 0;
}
