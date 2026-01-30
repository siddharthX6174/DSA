#include<bits/stdc++.h>
using namespace std;
bool isVowel(char x) {
    if (x == 'a' or x == 'A' or x == 'e' or x == 'E' or x == 'i' or x == 'I' or x == 'o' or x == 'O' or x == 'u' or x == 'U') {
        return true;
    }
    return false;
}
bool halvesAreAlike(string s) {
    int n = s.size();
    int toIterate = n / 2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < toIterate; i++) {
        if (isVowel(s[i])) {
            cnt1++;
        }
    }
    for (int i = toIterate; i < n; i++) {
        if (isVowel(s[i])) {
            cnt2++;
        }
    }
    return (cnt1 == cnt2);
}

int main() {
    string s;
    cin >> s;
    cout << halvesAreAlike(s) << endl;
    return 0;
}
