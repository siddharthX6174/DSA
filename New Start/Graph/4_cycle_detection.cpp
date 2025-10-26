# include <bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
	map<T, list<T>> mp;// adjacency list
public:

	void addEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	/*
		DFS_node: Check if there is a cycle in the graph from the current node.
	*/

	bool dfs_helper(T node, map<T, bool>& visited, T parent) {
		visited[node] = 1;

		for (auto nbr : mp[node]) {

			if (visited[nbr] == 0) {
				bool cycle = dfs_helper(nbr, visited, node);
				if (cycle) {
					return true;
				} else if (nbr != parent) {
					// this is a backedge
					return true;
				}
			}
		}
		return false;
	}

	bool dfs(T src) {
		map<T, bool> visited;

		for (auto x : mp) {
			visited[x.first] = 0;
		}

		return dfs_helper(src, visited, -1);
	}



	void print() {

		for (pair<T, list<T>>x : mp) {
			T node = x.first;
			list<T> nbr = x.second;

			cout << node << " ---> ";

			for (T y : nbr) {
				cout << y << "  ";
			}

			cout << endl;
		}
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

	cout << gr.dfs(1);
}