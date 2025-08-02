# include <iostream>
# include <string>

int main() {
	int t{};
	std::cin >> t;
	while (t--) {
		std::string number;
		std::cin >> number;

		int length = number.length();
		int digits[length];
		for (int i{}; i < length; i++) {
			digits[i] = number[i] - '0';
		}

		int a{(digits[0] * 10) + digits[1]};
		int b{(digits[2] * 10) + digits[3]};

		int year = (digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3]);

		if (year == ((a + b) * (a + b))) {
			std::cout << a << " " << b;
		} else {
			std::cout << -1;
		}
	}

	return 0;

}