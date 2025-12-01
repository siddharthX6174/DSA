#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<int, list<int>> adj;
    map<int, int> degree;

    // Initialize
    for (int i = 1; i <= n; i++) {
        degree[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    int minRecognition = INT_MAX;

    // Find all triangles
    for (auto& [i, neighbors_i] : adj) {
        // For each pair of neighbors of i
        for (auto it_j = neighbors_i.begin(); it_j != neighbors_i.end(); it_j++) {
            int j = *it_j;
            if (j <= i) continue;

            for (auto it_k = neighbors_i.begin(); it_k != neighbors_i.end(); it_k++) {
                int k = *it_k;
                if (k <= j) continue;

                // Check if j and k are connected
                bool connected = false;
                for (int neighbor : adj[j]) {
                    if (neighbor == k) {
                        connected = true;
                        break;
                    }
                }

                if (connected) {
                    int sum = degree[i] + degree[j] + degree[k] - 6;
                    minRecognition = min(minRecognition, sum);
                }
            }
        }
    }

    if (minRecognition == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minRecognition << endl;
    }

    return 0;
}