#include<iostream>

int main() {
	int n;
	std::cin >> n;

	for (int row = 1; row <= n; row++) {
		for (int space = 1; space <= (row - 1); space++) {
			std::cout << "  ";
		}
		for (int star = 1; star <= n - row + 1; star++) {
			std::cout << "* ";
		}
		std::cout << std::endl;
	}

	return 0;
}