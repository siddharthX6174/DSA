# include <iostream>

int main() {
	int n{};
	std::cin >> n;

	int odd_sum{}, even_sum{}, count{};

	while (n != 0) {
		int digit = n % 10;
		n /= 10;
		count++;

		if (count % 2 == 0) {
			even_sum += digit;
		} else {
			odd_sum += digit;
		}
	}

	std::cout << odd_sum << std::endl << even_sum << std::endl;

	return 0;
}