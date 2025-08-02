# include <iostream>

int main() {
	int n{};
	std::cin >> n;
	int arr[100] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	int sum{};
	for (int i{0}; i < n; i++) {
		sum += arr[i];
		std::cout << sum << " ";
	}
	return 0;
}