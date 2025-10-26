# include <bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
private:
	map<T, list<T>>mp;
public:
	void addEdge(T x, T y, bool direction) {
		mp[x].push_back(y);
		if (direction == 0) {
			mp[y].push_back(x);
		}
	}

	void print() {
		for (pair<T, list<T>> x : mp) {
			T node = x.first;
			list<T> nbr = x.second;

			cout << node << " --> ";

			for (T y : nbr) {
				cout << y << " ";
			}

			cout << endl;
		}
	}

	void bfs(T src) {
		// take the visited mark
		map<T, bool> visited;
		for (auto x : mp) {
			visited[x.first] == 0;
		}

		// make the queue to perform bfs
		queue<T> q;
		q.push(src);

		visited[src] = 1;

		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();

			for (T nbr : mp[node]) {
				if (visited[nbr] == 0) {
					q.push(nbr);
					visited[nbr] = 1;
				}
			}
		}
	}

};


int main() {
	int n, m;
	bool direction;
	cin >> n >> m >> direction;

	graph<int> gr;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		gr.addEdge(x, y, direction);
	}

	gr.print();

	cout << endl << endl;

	// call the bfs function
	gr.bfs(1);

	return 0;
}