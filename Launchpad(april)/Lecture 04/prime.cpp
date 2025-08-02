#include <iostream>

int main() {

	int n{};
	std::cin >> n;

	int i = 2;

	int flag{0};

	while (i <= n - 1) {

		// My current number is n and I want to check is n is divisible by current i or not
		if ((n % i) == 0) {
			std::cout << "Not Prime" << std::endl;
			//return 0;
			flag = 1;
		}

		i += 1;
	}

	if (flag == 1) { std::cout << "NOT PRIME"}

	std::cout << "Prime";
}