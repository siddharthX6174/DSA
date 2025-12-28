#include<bits/stdc++.h>
using namespace std;

// bool check(int n) {
//     string s = to_string(n);

//     for (char c : s) {
//         if (c != '1') {
//             return false;
//         }
//     }
//     return true;
// }

// int LENGTH(int n) {
//     string s = to_string(n);

//     return s.size();
// }

// int minAllOneMultiple(int k) {

//     int ans{ -1};

//     for (int i = k + 1; i <= 1e7; i++) {
//         if (i % k == 0) {
//             if (check(i)) {
//                 ans = LENGTH(i);
//                 break;
//             }
//         }
//     }

//     return ans;

// }

int minAllOneMultiple(int k) {
    if (k % 2 == 0 || k % 5 == 0)
        return -1;  // impossible case

    int remainder = 0;

    for (int length = 1; length <= k; length++) {
        remainder = (remainder * 10 + 1) % k;
        if (remainder == 0)
            return length;
    }

    return -1;
}


int main() {
    cout << minAllOneMultiple(2);
}
