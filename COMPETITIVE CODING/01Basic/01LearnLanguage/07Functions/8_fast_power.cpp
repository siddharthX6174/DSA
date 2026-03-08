#include<iostream>
#include<cmath>
using namespace std;

// long long fast_pow(long long a, long long b) {
//     long long res = 1;

//     while (b > 0) {
//         if (b % 2 == 1) {
//             res = res * a;
//         }
//         a = a * a;
//         b = b / 2;
//     }

//     return res;
// }

// int main() {
//     int a{}, b{}, c{}, d{};
//     cin >> a >> b >> c >> d;

//     bool is_big = false;
//     is_big = (fast_pow(a, b) > fast_pow(c, d));
//     if (is_big) {
//         cout << "YES\n";
//     } else {
//         cout << "NO\n";
//     }
//     return 0;
// }

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long double left = b * log(a);
    long double right = d * log(c);

    if (left > right)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}