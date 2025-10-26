#include <bits/stdc++.h>
using namespace std;

unordered_map<string, long long> memo;

string encode(const vector<int>& arr) {
    if (arr.empty()) return "";
    string s;
    s.reserve(arr.size() * 3); // Reserve space to avoid reallocations
    for (int x : arr) {
        s += to_string(x) + ",";
    }
    return s;
}

long long solve(vector<int>& arr) {
    if (arr.empty()) return 0;
    int n = arr.size();
    if (n % 3 != 0) return -1;

    string key = encode(arr);
    auto it = memo.find(key);
    if (it != memo.end()) return it->second;

    long long result = LLONG_MAX;

    // Optimization: Try removing triplets starting from first element
    // This reduces branching factor significantly
    int first = arr[0];
    vector<int> positions;
    for (int i = 0; i < n; i++) {
        if (arr[i] == first) {
            positions.push_back(i);
        }
    }

    // If we have at least 3 occurrences of first element
    if (positions.size() >= 3) {
        int m = positions.size();
        for (int p1 = 0; p1 < m - 2; p1++) {
            for (int p2 = p1 + 1; p2 < m - 1; p2++) {
                for (int p3 = p2 + 1; p3 < m; p3++) {
                    int i = positions[p1];
                    int j = positions[p2];
                    int k = positions[p3];

                    long long cost = min(j - i, k - j);

                    vector<int> remaining;
                    remaining.reserve(n - 3);
                    for (int idx = 0; idx < n; idx++) {
                        if (idx != i && idx != j && idx != k) {
                            remaining.push_back(arr[idx]);
                        }
                    }

                    long long subCost = solve(remaining);
                    if (subCost != -1) {
                        result = min(result, cost + subCost);
                    }
                }
            }
        }
    }

    // Also try without using first element (if it appears in other triplets)
    if (positions.size() < 3) {
        // First element cannot form a triplet with itself
        // Try other triplets
        for (int i = 0; i < n; i++) {
            if (i == 0) continue; // Skip first element
            for (int j = i + 1; j < n; j++) {
                if (arr[i] != arr[j]) continue;
                for (int k = j + 1; k < n; k++) {
                    if (arr[j] != arr[k]) continue;

                    long long cost = min(j - i, k - j);

                    vector<int> remaining;
                    remaining.reserve(n - 3);
                    for (int idx = 0; idx < n; idx++) {
                        if (idx != i && idx != j && idx != k) {
                            remaining.push_back(arr[idx]);
                        }
                    }

                    long long subCost = solve(remaining);
                    if (subCost != -1) {
                        result = min(result, cost + subCost);
                    }
                }
            }
        }
    }

    long long ans = (result == LLONG_MAX) ? -1 : result;
    memo[key] = ans;

    // Memory management: keep memo size bounded
    if (memo.size() > 100000) {
        memo.clear();
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;

            vector<int> sub(a.begin() + l, a.begin() + r + 1);

            // Clear memo periodically to prevent memory buildup
            if (memo.size() > 50000) {
                memo.clear();
            }

            cout << solve(sub) << "\n";
        }

        memo.clear(); // Clear after each test case
    }

    return 0;
}