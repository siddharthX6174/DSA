#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int res = 0;
        for (int m = 1; m <= 100; ++m) {
            for (int i = 0; i < n; ++i) {
                if (a[i] == m) {
                    int l = i;
                    int r = i;
                    while (l > 0 && a[l - 1] >= m) {
                        l--;
                    }
                    while (r < n - 1 && a[r + 1] >= m) {
                        r++;
                    }
                    vector<int> subarray(a.begin() + l, a.begin() + r + 1);
                    sort(subarray.begin(), subarray.end());
                    int k = subarray.size();
                    int med = subarray[(k + 1) / 2 - 1];
                    res = max(res, med - m);
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}