#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;

    long long arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long pre[n];
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }

    while (q--) {
        int a, b;
        std::cin >> a >> b;

        long long ans;
        if (a == 1) {
            ans = pre[b - 1];
        } else {
            ans = pre[b - 1] - pre[a - 2];
        }

        std::cout << ans << "\n";
    }

    return 0;
}
