# include <iostream>

int main() {

	int n{};
	std::cin >> n;

	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	bool ans{true};

	for (int i{1}; i < n; i++) {

		if (arr[i] > arr[i - 1]) {
			if (arr[i] < arr[i - 1]) {
				ans = false;
			}
		}

		else if (arr[i] == arr[i - 1]) {
			if (arr[i] > arr[i - 1]) {
				ans = false;
			}
		}

		else {
			if (arr[i] > arr[i - 1]) {
				ans = false;
			}
		}
	}

	std::cout << ans << " ";

	return 0;

}