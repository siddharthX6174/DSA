#include<iostream>

int main() {
	int n;
	std::cin >> n;

	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n - (row - 1); col++) {
			std::cout << "* ";
		}
		std::cout << std::endl;
	}

	return 0;
}