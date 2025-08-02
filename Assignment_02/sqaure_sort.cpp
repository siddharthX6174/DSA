#include <iostream>
#include <algorithm>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {

    int n{};
    std::cin >> n;
    int a[n] {};
    for (int i{}; i < n; i++) {std::cin >> a[i];}

    for (int i{}; i < n; i++) {a[i] = a[i] * a[i];}



    selectionSort(a, n);

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}