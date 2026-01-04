#include<bits/stdc++.h>
using namespace std;
string reversePrefix(string s, int k) {
    string toReverse = "";
    int i;
    for (i = 0; i < k; i++) {
        toReverse += s[i];
    }
    reverse(toReverse.begin(), toReverse.end());
    while (i < s.size()) {
        toReverse += s[i];
        i++;
    }

    return toReverse;
}

int main() {
    string s = "xyz";
    int k = 2;

    cout << reversePrefix(s, k);
    return 0;
}