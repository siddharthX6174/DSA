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


    for (int i{}; i < n - 1; i++) {
        int j = i + 1, k = n - 1;

        while (j < k) {
            int sum = array[i] + array[j] + array[k];

            if (sum == target) {
                if (array[i] <= array[j] && array[j] <= array[k])
                {
                    std::cout << array[i] << ", " << array[j] << " and " << array[k] << std::endl;
                    j++;
                    k--;
                }

            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }

    }
    return 0;
}
