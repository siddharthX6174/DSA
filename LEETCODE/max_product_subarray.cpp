# include <iostream>
# include <algorithm>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}


	// doesn't work in negative integer case
	/*
		int curr_product = 1,  max_product {arr[0]};

		for (int i{}; i < n; i++) {
			curr_product *= arr[i];
			max_product = std::max(curr_product, max_product);
			if (curr_product < 0) {
				curr_product = 1;
			}
		}

		std::cout << max_product << std::endl;
	*/


	int prefix = 1, suffix = 1;
	int ans = INT_MIN;

	for (int i{}; i < n; i++) {
		if (prefix == 0) prefix = 1;
		if (suffix == 0) suffix = 1;

		prefix *= arr[i];
		suffix *= arr[n - i - 1];

		ans = std::max( ans, std::max(prefix, suffix));
	}

	std::cout << ans << std::endl;



	return 0;
}