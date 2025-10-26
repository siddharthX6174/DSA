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
		map<T, int>distance;

		for (auto x : mp) {
			distance[x.first] = INT_MAX;
		}

		queue<T>q;
		q.push(src);
		distance[src] = 0;


		while (!q.empty()) {
			T node = q.front();
			q.pop();

			for (T nbr : mp[node]) {
				if (distance[nbr] == INT_MAX) {
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
				}
			}
		}

		// I am printing out the distance of every node from src node
		// for (pair<T, int> x : distance) {
		// 	cout << src << " to " << x.first << " distance is : " << distance[x.first] << endl;
		// }

		// I am iterating over the map
		for (pair<T, list<T>> x : mp) {
			cout << src << " to " << x.first << " distance is : " << distance[x.first] << endl;
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