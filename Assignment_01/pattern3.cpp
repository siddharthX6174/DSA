#include<iostream>

int main() {
	int n;
	std::cin >> n;

	for (int row = 1; row <= n; row++) {
		for (int space = 1; space <= (n - row); space++) {
			std::cout << " " << " ";
		}
		for (int star = 1; star <= row; star++) {
			std::cout << "* ";
		}
		std::cout << std::endl;
	}

	return 0;
}