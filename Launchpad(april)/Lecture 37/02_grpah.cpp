#include <iostream>
#include <map>
#include <list>
#include <utility>
#include <queue>
using namespace std;

template<typename T>
class gr {
private:
	// Weighted adjacency list : node -> list of (neighbor, weight)
	map<T, list<pair<T, int>>> mp;

public:

	// Add edge with weight
	void AddEdge(T x, T y, int wt, bool direction) {
		mp[x].push_back({y, wt});
		if (direction == 0) { // undirected
			mp[y].push_back({x, wt});
		}
	}

	void bfs(T scr) {
		map<T, bool>visited;

		for (pair<T, list<T>> x : mp) {
			visited[x.first] = 0;
		}

		queue<T>q;
		q.push(scr);
		visited[scr] = 1;

		while (!q.empty()) {
			T node = q.front();
			q.pop()
		}
	}

	// Print adjacency list
	void Print() {
		for (pair<const T, list<pair<T, int>>> &x : mp) {
			T node = x.first;
			list<pair<T, int>> nbrs = x.second;

			cout << node << " : ";

			for (pair<T, int> &nbr : nbrs) {
				cout << "(" << nbr.first << "-->" << nbr.second << ") ";
			}
			cout << endl;
		}
		cout << "------------------------------" << endl;
	}
};


int main() {
	int n, m, direction;
	cin >> n >> m >> direction;

	gr<int> G;

	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		G.AddEdge(x, y, wt, direction);
	}

	G.Print();

	return 0;
}
