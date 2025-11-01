#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
public:
	map<T, int> degree;

	void addEdge(T x, T y) {
		degree[x] += 1;
		degree[y] += 1;
	}

	void printAns(int n) {
		for (int i = 1; i <= n; i++) {
			cout << degree[i] << endl;
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	Graph<int> gr;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.addEdge(x, y);
	}

	gr.printAns(n);
	return 0;
}