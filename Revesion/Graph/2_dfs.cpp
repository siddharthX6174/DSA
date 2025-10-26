# include <bits/stdc++.h>
using namespace std;

/*
	Tree m hum sirf niche hi ja skte hain.. par graph m aisa nhi hota tum jate
	rhte ho jabtak ek reasta hai dfs m .... hoskta hai nodes repeat krjaye
	isiliiye tumko
	-> for every node uske parent ka pta hona chiye
	-> ya fir tum ek visited mark rakho **

	current node k nbr par chle jao aur bolo pure graph par jane ko
*/

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


	void dfs_helper(T node, map<T, bool>& visited) {
		cout << node << "-> ";

		visited[node] = 1; // mark visited

		for (auto nbr : mp[node]) {
			if (visited[nbr] == 0) {
				dfs_helper(nbr, visited);
			}
		}
	}

	void dfs(T src) {
		map<T, bool> visited;
		for (auto x : mp) { // not necessary to write this statement
			visited[x.first] = 0;
		}

		dfs_helper(src, visited);
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

	cout << endl << endl;

	gr.dfs(1);

	return 0;
}