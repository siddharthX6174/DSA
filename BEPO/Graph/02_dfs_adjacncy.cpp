#include<bits/stdc++.h>
using namespace std;
// undirected unweighted graph

template<typename T>
class Graph {
private:
	map<T, list<T>> mp; // Adjacency list
public:
	void addEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	void dfs_helper(T node, map<T, bool>& visited) {
		cout << node << " ";
		visited[node] = 1;

		// is node k nbr par chle jao
		for (auto nbr : mp[node]) {
			if (visited[nbr] == 0) {
				dfs_helper(nbr, visited);
			}
		}
	}

	void Dfs(T src) {
		map<T, bool> visited;

		for (auto x : mp) {
			visited[x.first] = 0;
		}

		dfs_helper(src, visited);
	}

	void Print() {
		for (pair<T, list<T>> x : mp) {
			T node = x.first;
			list<T> nbr = x.second;

			cout << node << " ---> ";

			for (T y : nbr) {
				cout << y << " ";
			}

			cout << endl;
		}
	}
};

int main() {
	int n, m, direction; // no of nodes and no of edges
	cin >> n >> m >>  direction;

	Graph<int> gr;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y, direction);
	}

	gr.Print();

	return 0;

}