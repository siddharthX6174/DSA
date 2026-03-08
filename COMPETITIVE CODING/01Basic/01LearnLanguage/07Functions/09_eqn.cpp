#include<iostream>
#include<cstdint>
using namespace std;

#define int long long

long long fast_pow(long long a, long long b) {
    long long res = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a;
        }
        a = a * a;
        b = b / 2;
    }

    return res;
}


int32_t main() {
    int x{}, n{};
    cin >> x >> n;

    int s{};
    int a{2};

    while (a <= n) {
        s += fast_pow(x, a);
        a += 2;
    }

    cout << s << "\n";
    return 0;
}