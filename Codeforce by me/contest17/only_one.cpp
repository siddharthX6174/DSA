#include <iostream>
#include <algorithm>

int main() {
    int t{};
    std::cin >> t;

    while (t--) {
        int x{};
        std::cin >> x;

        int y = 9; // Initialize with maximum digit

        while (x > 0) {
            int digit = x % 10;
            y = std::min(digit, y);
            x /= 10;
        }

        std::cout << y << std::endl;
    }

    return 0;
}
