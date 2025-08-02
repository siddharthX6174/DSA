# include <iostream>
# include <climits>

int main() {
	int n{};
	std::cin >> n;
	int arr[100] {};
	for (int i{}; i < n; i++) std::cin >> arr[i];

	int max{INT_MIN};

	for (int i{}; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	std::cout << max << std::endl;

	return 0;
}