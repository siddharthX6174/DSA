#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
	map<T, list<pair<T, int>>> mp;
public:
	void addEdge(T x, T y, int wt) {
		mp[x].push_back({y, wt});
		mp[y].push_back({x, wt});
	}

	void print() {
		cout << "node " << "{nbr, weight}\n";
		for (auto x : mp) {
			T node = x.first;
			auto nbr = x.second;

			cout << node << " --> ";

			for (auto y : nbr) {
				cout << "{" << y.first << ", " << y.second << "}   ";
			}

			cout << endl;
		}
	}
};

int main() {
	int vertex, edge;
	cin >> vertex >> edge;

	Graph<int> gr;

	for (int i = 0; i < edge; i++) {
		int x , y, wt;
		cin >> x >> y >> wt;
		gr.addEdge(x, y, wt);
	}

	gr.print();

	return 0;
}