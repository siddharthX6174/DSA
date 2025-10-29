# include <bits/stdc++.h>
using namespace std;

template<typename T> // node
class Graph {
	int v; // vertex
	vector<vector<int>> connection;
public:
	Graph(int v) {
		this->v = v;
		connection.resize(v, vector<int>(v, 0));
	}

	void addEdge(int x, int y, int wt) {
		connection[x][y] = wt;
		connection[y][x] = wt;
	}

	void print() {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (connection[i][j] > 0) {
					cout << "(" << i << " " << j << ") -> " << connection[i][j] << "  ";
				}
			}
			cout << endl;
		}
	}
};


int main() {
	int vertex, edge;
	cin >> vertex >> edge;

	Graph<int> gr(vertex);

	for (int i = 0; i < edge; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		gr.addEdge(x, y, wt);
	}

	gr.print();
	return 0;
}