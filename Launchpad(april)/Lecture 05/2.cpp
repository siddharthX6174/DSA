#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int i = 1;
	int x;
	int sum = 0;

	while (i <= n) {
		std::cin >> x;
		sum += x;
		std::cout << x << " ";
		i += 1;
	}

	std::cout << std::endl << sum << std::endl;

	return 0;
}