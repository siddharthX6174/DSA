# include <iostream>
# include <climits>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	int max_product = INT_MIN;

	for (int s{}; s < n; s++) {
		for (int e{s}; e < n; e++) {
			int product {1}; `
			for (int k = s; k <= e; k++) {
				product *= arr[k];
			}
			if (product > max_product) {
				max_product = product;
			}

		}
		//std::cout << std::endl;
	}

	std::cout << max_product ;
	return 0;
}