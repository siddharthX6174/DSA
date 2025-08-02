#include <iostream>

int main() {
    // Inputs
    int n{}, m{};
    std::cin >> n;
    int arr_1[n];
    for (int i{}; i < n; i++) std::cin >> arr_1[i];

    std::cin >> m;
    int arr_2[m];
    for (int i{}; i < m; i++) std::cin >> arr_2[i];

    int ans[100] {};
    int index{};
    int carry = 0;

    int i{n - 1}, j{m - 1};
    while (i >= 0 || j >= 0 || carry) {
        int a = (i >= 0) ? arr_1[i] : 0;
        int b = (j >= 0) ? arr_2[j] : 0;
        int sum = a + b + carry;

        ans[index++] = sum % 10;
        carry = sum / 10;

        i--;
        j--;
    }

    while (index--) {
        std::cout << ans[index] << ", ";
    }
    std::cout << "END";

    return 0;
}
