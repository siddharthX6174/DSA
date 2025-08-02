# include <iostream>

int main() {
	int t {};  // no of test cases
	std::cin >> t;

	int n{};

	for (int i{}; i < t; i++) {
		int a{}, sum{};
		std::cin >> n; q
		for (int j{}; j < n; j++) {
			std::cin >> a;
			sum += a;
		}
		if (sum % 2 == 0) {
			std::cout << "NO" << std::endl;
		} else {
			std::cout << "YES" << std::endl;
		}
	}

	return 0;
}