#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a = -1, b = -1, c = -1;

        // find first divisor
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a = i;
                n /= i;
                break;
            }
        }

        // find second divisor
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0 && i != a) {
                b = i;
                n /= i;
                break;
            }
        }

        c = n;

        if (a != -1 && b != -1 && c != a && c != b && c > 1) {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}