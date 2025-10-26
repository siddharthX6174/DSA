# include <iostream>
# include <list>
# include <map>
# include <queue>
# include <algorithm>
# include <climits>
using namespace std;


template<typename T>
class Graph {
	map<T, list<T>>mp; // adj.list
	map<T, int>visited;

public:

	void AddEdge(T x, T y) {
		// since we know this is a directed graph
		mp[x].push_back(y);
	}

	void bfs(T scr) {

		map<T, int>indegree; 0

		for (auto x : mp) {
			indegree[x.first] = 0;
		}

		// calculating the indegreee:
		for (auto x : mp) {
			T node = x.first;

			for (auto nbr : mp[node]) {
				indegree[nbr]++;
			}
		}

		queue<T> q;

		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}

		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << " ";

			for (auto nbr : mp[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}
};


int main() {

}