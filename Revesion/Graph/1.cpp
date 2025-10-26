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
		for (pair<T, list<T>> p : mp) {
			T node = p.first;
			list<T> nbr = p.second;

			cout << node << " --> ";

			for (T x : nbr) {
				cout << x << " ";
			}

			cout << endl;
		}
	}

};


int main() {
	int n, m, direction;
	cin >> n >> m >> direction;

	graph<int> gr;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		gr.addEdge(x, y, direction);
	}

	gr.print();

	return 0;
}