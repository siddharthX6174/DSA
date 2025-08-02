#include <iostream>
#include <algorithm>
#include <climits>

const int OFFSET = 10000; // Shift to handle negative numbers
const int MAX_RANGE = 20001; // Range [-10000, 10000] inclusive

void counting_sort(int arr[], int n);

int main() {
    int n;
    std::cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    counting_sort(arr, n);

    int ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += arr[i];
    }

    std::cout << ans << std::endl;

    return 0;
}

void counting_sort(int arr[], int n) {
    int freq_arr[MAX_RANGE] = {};  // Covers range -10000 to 10000

    // Count frequency of each number using offset
    for (int i = 0; i < n; i++) {
        freq_arr[arr[i] + OFFSET]++;
    }

    int index = 0;
    for (int i = 0; i < MAX_RANGE; i++) {
        while (freq_arr[i] > 0) {
            arr[index++] = i - OFFSET;
            freq_arr[i]--;
        }
    }
}
