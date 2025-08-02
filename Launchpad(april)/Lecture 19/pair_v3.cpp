#include<iostream>
#include<climits>

int n{};
int ans = INT_MAX;


// OPtimizations : Try to apply recursion from back if you can
void F2 (int a, int b, int count) {
    if (a == 1 && b == 1) {
        ans = std::min(ans, count);
        return;
    }

    // Move backwards if possible
    if (a - b > 0) {
        F2(a - b, b, count + 1);
    }
    if (b - a > 0) {
        F2(a, b - a, count + 1);
    }
}

int main() {
    std::cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        // For each possible split (n - i, i)
        F2(n - i, i, 1);
    }

    if (ans == INT_MAX) {
        ans = 0; // No path found
    }
    std::cout << ans << std::endl;

}
