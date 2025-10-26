# include <bits/stdc++.h>
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
		for (auto x : mp) {
			T node = x.first;
			list<T> nbr = x.second;
			cout << node << " --> ";
			for (auto y : nbr) {
				cout << y << " ";
			}
			cout << endl;
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

// modified for finiding the connected components
	void dfs() {
		map<T, bool> visited;
		for (auto x : mp) {
			visited[x.first] = 0;
		}

		int count = 1;

		for (auto x : mp) {
			if (visited[x.first] == 0) {
				cout << "Component number : " << count << " --> ";
				dfs_helper(x.first, visited);
				count ++;
				cout << endl;
			}
		}

		cout << "Total Components nummber : " << count - 1 << endl;
	}
};


int main() {
	int n, m, direction;
	cin >> n >> m >> direction;

	graph<int> gr;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		gr.addEdge(x, y, direction);
	}

	gr.print();
	cout << endl << endl;

	gr.dfs();
	return 0;
}