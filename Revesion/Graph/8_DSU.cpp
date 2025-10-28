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
	}

	int find(int node) {
		if (parent[node] == -1) {
			return node;
		}
		// path compression by dp
		return parent[node] = find(parent[node]); // result storing
	}

	void Union(int node1, int node2) {
		int s1 = find(node2)
		         int s2 = find(node1)

		if (s1 != s2) {
			// this means they belong to different set and we can merge them
			// union by rank
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
}

int main() {

}