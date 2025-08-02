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

void selection_sort (int arr[], int n) {
	for (int k{}; k < n - 1; k++) {
		int mini = k;
		for (int i{k + 1}; i < n; i++) {
			if (arr[i] < arr[mini]) {
				mini = i;
			}
		}
		std::swap(arr[k], arr[mini]);
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
