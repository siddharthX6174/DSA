# include <iostream>

int linear_search (int arr[], int n, int target) {
	for (int i{}; i < n; i++) {
		if (arr[i] == target) {
			return i;
			break;
		}
	}
	return -1;
}

int main() {
	int n{}, target{};
	std::cin >> n;
	int arr[100] {};
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	std::cin >> target;

	std::cout << linear_search(arr, n, target);

	return 0;
}