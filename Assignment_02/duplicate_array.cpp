#include <iostream>

int main() {
	int n{};
	std::cin >> n;
	int arr[100] {};
	for (int i = 0; i < n; i++) std::cin >> arr[i];

	int unique_arr[100] {};
	int unique_count{};

	for (int i = 0; i < n; i++) {
		bool is_duplicate = false;
		for (int j = 0; j < unique_count; j++) {
			if (arr[i] == unique_arr[j]) {
				is_duplicate = true;
				break;
			}
		}
		if (!is_duplicate) {
			unique_arr[unique_count++] = arr[i];
		}
	}

	std::cout << unique_count << std::endl; // unique array count
	// for (int i = 0; i < unique_count; i++) {
	// 	std::cout << unique_arr[i] << " ";
	// }

	for (int i{}; i < unique_count; i++) {
		arr[i] = unique_arr[i];
	}

	for (int i{}; i < unique_count; i++) {
		std::cout << unique_arr[i] << " ";
	}

	return 0;
}
