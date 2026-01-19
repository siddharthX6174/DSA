#include<bits/stdc++.h>
using namespace std;

void solve(int n, int &match) {
    if (n == 1) {
        return;
    }

    if (n % 2 == 0) {
        match += n / 2;
        solve(n / 2, match);
    }
    else {
        match += (n - 1) / 2;
        solve(((n - 1) / 2) + 1, match);
    }
}

int main() {
    int n;
    cin >> n;

    int match = 0;
    solve(n, match);

    cout << match;
    return 0;
}
