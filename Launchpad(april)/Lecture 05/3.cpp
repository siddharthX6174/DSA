# include <iostream>

int main() {

	int x;
	int sum = 0;

	while (std::cin >> x) {
		sum += x;
		std::cout << x << " ";
	}

	std::cout << std::endl << sum << std::endl;
}