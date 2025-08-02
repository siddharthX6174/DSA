# include <iostream>

bool lucky_digits (int n) {
	while (n > 0) {
		int digit = n % 10;
		if ((digit != 4) and (digit != 7)) {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main()  {
	int n{};
	std::cin >> n;

	if (lucky_digits(n) == true) {
		std::cout << "YES";
		return 0;
	}

	// Check if n is divisible by any lucky number between 1 and n
	for (int i = 1; i <= n; ++i) {
		if (lucky_digits(i) && n % i == 0) {
			std::cout << "YES";
			return 0;
		}
	}

	std::cout << "NO";
	return 0;
}