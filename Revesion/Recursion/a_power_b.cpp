#include <iostream>

/*
 calculate a^b , 2^5
 task - a*a*a*a*a
 */

int a{};
int ans = 1;

int solve(int b) {
    // base case
    if (b <= 1) {
        return a;
    }
    // task -
    ans = a * solve(b - 1);
    return ans;
}

int main() {
    std::cin >> a;
    int b{}; // raise to the power
    std::cin >> b;

    std::cout << solve(b) << std::endl;
    return 0;
}