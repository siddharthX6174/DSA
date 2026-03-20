#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> small, large;

    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            small.push_back(i);

            if (i != n / i) {
                large.push_back(n / i);
            }
        }
    }

    reverse(large.begin(), large.end());

    // merge
    vector<long long> divisors = small;
    for (auto x : large) divisors.push_back(x);

    if (k > divisors.size()) {
        cout << -1 << endl;
    } else {
        cout << divisors[k - 1] << endl;
    }

    return 0;
}