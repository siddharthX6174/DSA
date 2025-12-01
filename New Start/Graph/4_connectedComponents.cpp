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

	void dfs() {
		map<T, bool> visited;
		int count = 1;

		for (auto x : mp) {
			T node = x.first;
			list<T> nbr = x.second;

			if (visited[node] == 0) {
				cout << "Component No: " << count << " --> ";
				dfs_helper(node, visited);
				count++;
				cout << endl;
			}
		}
		cout << "Total Components : " << count - 1 << endl;
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

	//gr.print();

	// cout << endl << endl;

	gr.dfs();
}