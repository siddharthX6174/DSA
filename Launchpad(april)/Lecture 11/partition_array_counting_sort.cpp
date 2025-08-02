# include <iostream>
# include <algorithm>
# include <climits>

void counting_sort (int arr[], int n, int max_size);

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	int maxi {INT_MIN};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
		maxi = std::max(maxi, arr[i]);
	}

	counting_sort(arr, n, maxi);

	int ans{0};
	for (int i{}; i < n; i += 2) {
		ans += arr[i];
	}

	std::cout << ans << std::endl;

	return 0;
}

void counting_sort (int arr[], int n, int max_size) {
	int freq_arr[max_size + 1] {};
	for (int i{}; i < n; i++) {
		int ce = arr[i];
		freq_arr[ce]++;
	}

	int current_element_index {}; // Index to place elements back to original array
	for (int i{}; i <= max_size; i++) {
		// For each number 'i', add it to 'arr' 'freq_arr[i]' times
		for (int j{}; j < freq_arr[i]; j++) {
			arr[current_element_index] = i;
			current_element_index++;
		}
	}
}