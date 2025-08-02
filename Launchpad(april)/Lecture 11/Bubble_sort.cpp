# include <iostream>
# include <algorithm>

void Bubble_sort (int arr[], int n) {

	for (int task {0}; task < n - 1; task++) {
		for (int i{0}; i < n - task - 1; i++) {
			if (arr[i] > arr[i + 1] ) {
				std::swap(arr[i], arr[i + 1]);

			}
		}
	}

}

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	if (n > 1) {
		Bubble_sort(arr, n);
	}

	for (int i{}; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}
