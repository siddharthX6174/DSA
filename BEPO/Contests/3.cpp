#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 998244353;

struct Solver {
    int n;
    string s;
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> order;
    vector<vector<long long>> dp, f;

    Solver(int n, string s) : n(n), s(s), adj(n + 1), parent(n + 1, 0), dp(n + 1, vector<long long>(n + 1, 0)), f(n + 1, vector<long long>(n + 1, 0)) {}

    void build_tree(int u, int p) {
        parent[u] = p;
        for (int v : adj[u]) {
            if (v != p) build_tree(v, u);
        }
        order.push_back(u); // Post-order traversal
    }

    void solve() {
        build_tree(1, 0);

        // Verify if it's a valid tree (implicitly handled by DFS and n-1 edges)
        if (order.size() != n) return;

        for (int u : order) {
            for (int v : order) {
                if (s[u - 1] == s[v - 1]) {
                    long long children_sum = 0;
                    for (int cu : adj[u]) {
                        if (cu == parent[u]) continue;
                        for (int cv : adj[v]) {
                            if (cv == parent[v]) continue;
                            children_sum = (children_sum + f[cu][cv]) % MOD;
                        }
                    }
                    dp[u][v] = (1 + children_sum) % MOD;
                }

                long long total = dp[u][v];
                for (int cu : adj[u]) {
                    if (cu != parent[u]) total = (total + f[cu][v]) % MOD;
                }
                for (int cv : adj[v]) {
                    if (cv != parent[v]) total = (total + f[u][cv]) % MOD;
                }
                for (int cu : adj[u]) {
                    if (cu != parent[u]) {
                        for (int cv : adj[v]) {
                            if (cv != parent[v]) {
                                total = (total - f[cu][cv] + MOD) % MOD;
                            }
                        }
                    }
                }
                f[u][v] = total;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << f[i][i] << (i == n ? "" : " ");
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solver sol(n, s);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            sol.adj[u].push_back(v);
            sol.adj[v].push_back(u);
        }
        sol.solve();
    }
    return 0;
}