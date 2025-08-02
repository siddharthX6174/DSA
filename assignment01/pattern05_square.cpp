#include <iostream>

int main() {
    int n{};
    std::cin >> n;

    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= n; ++col) {
            if (col <= row) {
                std::cout << row << " ";
            } else {
                std::cout << col << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
