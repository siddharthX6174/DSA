#include <bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
private:
	//map<T, list<T>> mp;
	map<T, multiset<T>> mp;
public:

	void addEdge(T x, T y) {
		//mp[x].push_back(y);
		mp[x].insert(y);
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

	void dfs_helper(T node, map<T, int>& visited, list<T>& ordering) {
		visited[node] = 1;

		for (auto nbr : mp[node]) {
			if (visited[nbr] == 0) {
				dfs_helper(nbr, visited, ordering);
			}
		}
		ordering.push_front(node);
		return;

	}

	void dfs() {
		map<T, int> visited;
		list<T> ordering;
		for (auto x : mp) visited[x.first] = 0;

		for (auto x : mp) {
			T node = x.first;
			if (!visited[node]) {
				dfs_helper(node, visited, ordering);
			}
		}

		for (auto x : ordering) {
			cout << x << " ";
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

	gr.print();
	cout << endl << endl;

	gr.dfs();

	return 0;
}
