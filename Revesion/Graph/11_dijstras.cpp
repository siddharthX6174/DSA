#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;  // (distance, node)

// Dijkstra's Algorithm Function
void dijkstra(int src, int V, vector<vector<pii>> &adj) {
	vector<int> dist(V, INT_MAX);  // Distance array initialized to infinity
	priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap (distance, node)

	dist[src] = 0;
	pq.push({0, src});

	while (!pq.empty()) {
		int d = pq.top().first;  // Current distance
		int u = pq.top().second; // Current node
		pq.pop();

		// Skip if this distance is already larger (not the best)
		if (d > dist[u]) continue;

		// Explore all adjacent nodes
		for (auto edge : adj[u]) {
			int v = edge.first;
			int w = edge.second;

			// Relaxation step
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	// Print the shortest distances
	cout << "Vertex\tDistance from Source\n";
	for (int i = 0; i < V; i++) {
		cout << i << "\t\t" << dist[i] << "\n";
	}
}

// Main function
int main() {
	int V, E;
	cout << "Enter number of vertices and edges: ";
	cin >> V >> E;

	vector<vector<pii>> adj(V);

	cout << "Enter edges (u v w):\n";
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});  // Comment this line if the graph is directed
	}

	int src;
	cout << "Enter source vertex: ";
	cin >> src;

	dijkstra(src, V, adj);

	return 0;
}
