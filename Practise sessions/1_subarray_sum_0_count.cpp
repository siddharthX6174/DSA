#include <iostream>
#include <algorithm>
#include <climits>

int main() {
    int n{};
    std::cin >> n;
    int arr[n] {};

    for (int i{}; i < n; i++) {
        std::cin >> arr[i];
    }

    // Build prefix sum array and find min/max prefix sums
    int prefix_sum[n] {};
    prefix_sum[0] = arr[0];
    int maxi = prefix_sum[0];
    int mini = prefix_sum[0];

    for (int i{1}; i < n; i++) {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
        maxi = std::max(maxi, prefix_sum[i]);
        mini = std::min(mini, prefix_sum[i]);
    }

    // Calculate range for frequency array
    int range = maxi - mini + 1;
    int freq[range] {};

    // Initialize count for sum 0 (empty subarray case)
    freq[0 - mini] = 1;  // This handles prefix sums that equal 0

    int total_subarray_whose_sum_is_0{};

    for (int i{}; i < n; i++) {
        // Add the count of previous occurrences of this sum
        total_subarray_whose_sum_is_0 += freq[prefix_sum[i] - mini];

        // Update frequency count for current prefix sum
        freq[prefix_sum[i] - mini]++;
    }

    std::cout << "Number of subarrays with sum 0: " << total_subarray_whose_sum_is_0 << std::endl;

    return 0;
}



// sum == k make slight change only
/*
    total += freq[prefix_sum[i] - k - mini]
    freq[prefix_sum[i] - k - mini]++;

*/