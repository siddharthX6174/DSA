#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
	map<T, T> mp;
public:

	map<T, int> degree;

	void addEdge(T x, T y) {
		mp[x] = y;
		degree[x] += 1;
		mp[y] = x;
		degree[y] += 1;
	}

	void printAns() {
		for (auto x : degree) {
			cout << x.second << endl;
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

	gr.printAns();
	return 0;
}