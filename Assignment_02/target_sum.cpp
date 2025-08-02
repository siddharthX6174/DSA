#include <iostream>
#include <algorithm>  // For std::sort

int main() {
    int n{};
    std::cin >> n;

    int array[1000]; // As per constraints (1 to 1000)
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    int target{};
    std::cin >> target;

    // Sort the array for two-pointer approach
    std::sort(array, array + n);

    int i = 0, j = n - 1;

    while (i < j) {
        int sum = array[i] + array[j];

        if (sum == target) {
            std::cout << array[i] << " and " << array[j] << std::endl;
            i++;
            j--;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return 0;
}
