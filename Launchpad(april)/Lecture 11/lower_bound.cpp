# include <iostream>

int lower_bound(int arr[], int n, int x) {
	int start = 0, end = n - 1, ans = n;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (arr[mid] >= x) {
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

int upper_bound(int arr[], int n, int x) {
	int start = 0, end = n - 1, ans = n;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (arr[mid] > x) {
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}

int main() {

	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}
	int x{};
	std::cin >> x;

	std::cout << lower_bound(arr, n, x) << std::endl;
	std::cout << upper_bound(arr, n, x) << std::endl;

	return 0;
}