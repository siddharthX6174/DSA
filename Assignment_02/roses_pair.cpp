#include <iostream>
#include <climits>

bool is_linear_search(int element, int arr[], int start, int end) {
	bool ans {false};
	for (int i = start; i < end; i++) {
		if (arr[i] == element) {
			ans = true;
		}
	}
	return ans;
}

void selection_sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		// Swap
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

int main() {

	int t{};
	std::cin >> t;
	while (t--) {
		int n{};
		std::cin >> n;

		int arr[100] {};
		for (int i{}; i < n; i++) std::cin >> arr[i];

		selection_sort(arr, n); //  Sort the array

		int money{};
		std::cin >> money;

		int rose_1_cost{}, rose_2_cost{};
		int old_diff = INT_MAX;

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				bool is_there_2nd = is_linear_search(money - arr[i], arr, j, n);
				int temp_rose_1{}, temp_rose_2{}, new_diff{};

				if (is_there_2nd) {
					temp_rose_1 = arr[i];
					temp_rose_2 = money - arr[i];
					new_diff = temp_rose_2 - temp_rose_1;

					if (new_diff < old_diff) {
						old_diff = new_diff;
						rose_1_cost = temp_rose_1;
						rose_2_cost = temp_rose_2;
					}
				}
			}
		}

		std::cout << "Deepak should buy roses whose prices are " << rose_1_cost << " and " << rose_2_cost << std::endl;
	}

	return 0;
}
