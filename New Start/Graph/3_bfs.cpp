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



	void bfs(T src) {
		map<T, bool>visited;

		for (auto x : mp) {
			visited[x.first] = 0;
		}

		queue<T>q;
		q.push(src);

		visited[src] = 1;


		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ";

			for (auto nbr : mp[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = 1;
				}
			}
		}
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

	gr.bfs(1);
}