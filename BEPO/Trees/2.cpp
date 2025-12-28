#include<bits/stdc++.h>
using namespace std;

bool check(long long n) {
    string s = to_string(n);
    set<char>st;
    for (char c : s) {
        st.insert(c);
    }
    if (st.size() >= 2) {
        return true;
    }
    return false;
}
bool check2(long long n) {
    string s = to_string(n);
    int oddSum = 0, evenSum = 0;

    for (int i = 0; i < size(); i++) {
        int digit = s[i] - '0';
    }

    if ((i + 1) % 2 == 1) {
        oddSum += digit;
    } else {
        evenSum += digit;
    }

    return oddSum == evenSum;
}
long long countBalanced(long long low, long long high) {
    long long ans = 0;
    for (long long i = low; i <= high; i++) {
        bool op1 = check(i);
        bool op2 = check2(i);
        if (op1 == true and op2 == true) {
            ans++;
        }
    }
    return ans;
}

int main() {
    cout << countBalanced(1, 100);
}