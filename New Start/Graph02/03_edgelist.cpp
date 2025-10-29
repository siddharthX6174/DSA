#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
	map<pair<int, int>, int> mp; // edgelist representation (v1, v2), wt
public:
	void addEdge(T x, T y, T wt) {
		mp[ {x, y}] = wt;
		mp[ {y, x}] = wt;
	}

	void print() {
		for (auto &x : mp) {
			auto p = x.first; // pair<T,T>
			int wt = x.second;
			cout << "(" << p.first << ", " << p.second << ") --> "
			     << wt << endl;
		}
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	graph<int> gr;

	for (int i = 0; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		gr.addEdge(x, y, wt);
	}
	gr.print();
	return 0;
}