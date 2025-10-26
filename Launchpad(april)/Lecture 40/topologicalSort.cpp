# include <iostream>
# include <list>
# include <map>
# include <queue>
# include <algorithm>
# include <climits>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>>mp; // adj.list
	map<T, int>visited;

public:

	void AddEdge(T x, T y) {
		// since we know this is a directed graph
		mp[x].push_back(y);
	}

	void dfs_helper(T node, list<T>& ordering) {
		visited[node] = 1;

		for (auto nbr : mp[node]) {
			if (visited[nbr] == 0) {
				dfs_helper(nbr, ordering);
			}
		}


		ordering.push_front(node);
	}

	void dfs(T scr) {
		list<T> ordering; // Topological Sort Ordering.
		visited.clear();
		for (auto x : mp) {
			visited[x.first] = 0;
		}

		// Dfs call from each and every node.

		for (auto x : mp) {
			if (visited[node] == 0) {
				dfs_helper(node, ordering);
			}
		}

		for (auto x : ordering) {
			cout << x << " ";
		}

		cout << endl;
	}
}



int main() {

	int n, m;
	cin >> n >> m;

	Graph<int>gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.AddEdge(x, y);
	}

	// This node 0 is just for reresentation you could have taken any node in this scenerio
	gr.dfs(0);
}