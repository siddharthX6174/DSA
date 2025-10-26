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



	void dfs_helper(T node, map<T, bool>& visited) {
		cout << node << " ";
		visited[node] = 1;

		for (auto nbr : mp[node]) {

			if (visited[nbr] == 0) {
				dfs_helper(nbr, visited);
			}

		}
	}

	void dfs(T src) {
		map<T, bool> visited;

		// vector<bool> b;
		// vecctor se ki vector[node] par 0 pda hain ya 1 pda hain.

		for (auto x : mp) {
			visited[x.first] = 0;
		}

		dfs_helper(src, visited);
		// dfs lagana chate ho :
		// we want to apply dfs on multiple nodes...
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

	gr.print();

	cout << endl << endl;

	gr.dfs(1);
}