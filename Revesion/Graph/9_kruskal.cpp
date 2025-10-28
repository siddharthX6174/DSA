#include<bits/stdc++.h>
using namespace std;

class DSU {
	int *parent;
	int *rank;
	int component;
public:
	DSU(int n) {
		parent = new int[n + 1];
		rank = new int[n + 1];
		component = n;

		for (int i = 0; i <= n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int node) {
		if (parent[node] == -1) {
			return node;
		}
		return parent[node] = find(parent[node]);
	}

	void Union(int node1, int node2) {
		int s1 = find(node1);
		int s2 = find(node2);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
			component--;
		}
	}
};

class Graph {
	vector<vector<int>> edgelist;
	int nodes;

public:
	Graph(int nodes) {
		this->nodes = nodes;
	}

	void addEdge(int wt, int x, int y) {
		edgelist.push_back({wt, x, y});
	}

	int Kruskal_MST() {
		DSU s(nodes);

		sort(edgelist.begin(), edgelist.end());

		int Minimum_weight = 0;

		for (auto edge : edgelist) {
			int Weight = edge[0];
			int V1 = edge[1];
			int V2 = edge[2];

			if (s.find(V1) != s.find(V2)) {
				s.Union(V1, V2);
				Minimum_weight += Weight;
			}
		}
		return Minimum_weight;
	}
};

int main() {
	int node, edge;
	cin >> node >> edge;

	Graph gr(node);

	while (edge--) {
		int wt, x, y;
		cin >> wt >> x >> y;
		gr.addEdge(wt, x, y);
	}

	cout << gr.Kruskal_MST();
	return 0;
}
