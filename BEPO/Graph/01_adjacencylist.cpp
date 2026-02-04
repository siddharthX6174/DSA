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