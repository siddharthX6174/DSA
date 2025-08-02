#include <iostream>

int fibonacci(int index) {
    if (index == 0) return 0;
    if (index == 1) return 1;

    int t1 = 0, t2 = 1, term;
    for (int i = 2; i <= index; ++i) {
        term = t1 + t2;
        t1 = t2;
        t2 = term;
    }
    return t2;
}

int main() {
    int n;
    std::cin >> n;

    int k = 0; // Fibonacci index
    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= row; ++col) {
            std::cout << fibonacci(k) << " ";
            ++k;
        }
        std::cout << "\n";
    }

    return 0;
}
