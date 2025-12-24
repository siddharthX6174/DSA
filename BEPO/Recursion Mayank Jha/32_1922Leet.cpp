class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long fastPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (fastPow(5, even) * fastPow(4, odd)) % MOD;
    }
};
