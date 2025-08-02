# include <iostream>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int s{}; s < n; s++) {
		for (int e{s}; e < n; e++) {
			for (int k = s; k <= e; k++) {
				std::cout << arr[k] << " ";
			}
			std::cout << " ";
		}
		//std::cout << std::endl;
	}
}