# include <iostream>

int main() {
	int t{};
	std::cin >> t;

	while (t--) {
		int n{};
		std::cin >> n;
		int arr [n] {};
		for (int i{}; i < n; i++) {
			std::cin >> arr[i];
		}

		int same_num_idx{};
		for (int i{}; i < n; i++) {
			if (arr[i] == arr[i + 1]) {
				same_num_idx = i;
			}
		}

		int same_element_in_array = arr[same_num_idx];

		for (int i{}; i < n; i++) {
			if (arr[i] != same_element_in_array) {
				std::cout << i + 1 << std::endl;
			}
		}
	}

	return 0;
}