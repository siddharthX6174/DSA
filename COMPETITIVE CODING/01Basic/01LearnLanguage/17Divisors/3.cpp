#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// gcd
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// modular multiplication (avoid overflow)
ll mulmod(ll a, ll b, ll mod) {
    return (__int128)a * b % mod;
}

// modular exponentiation
ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

// Miller-Rabin (simplified)
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll x : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
        if (n % x == 0) return n == x;
    }
    ll d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, s++;

    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

// Pollard Rho
ll pollard(ll n) {
    if (n % 2 == 0) return 2;

    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;

    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;

        d = gcd(abs(x - y), n);

        if (d == n) return pollard(n); // retry
    }
    return d;
}

// factorization
void factor(ll n, vector<ll>& res) {
    if (n == 1) return;
    if (isPrime(n)) {
        res.push_back(n);
        return;
    }
    ll d = pollard(n);
    factor(d, res);
    factor(n / d, res);
}

int main() {
    ll n;
    cin >> n;

    vector<ll> factors;
    factor(n, factors);

    sort(factors.begin(), factors.end());

    for (auto& x : factors) {
        cout << x << " ";
    }

    for (auto x : factors) cout << x << " ";
}