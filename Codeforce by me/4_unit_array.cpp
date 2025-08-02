# include <iostream>

int main() {
	int t{};
	std::cin >> t;

	while (t--) {
		int n{};
		std::cin >> n;


		int count_pos{}, count_neg{}, a{};

		while (n--) {
			std::cin >> a;

			if (a == 1) {count_pos++;}
			else {count_neg++;}
		}

		int operation{};

		// ensure count_neg is even
		if (count_neg % 2 != 0) {
			operation++;
			count_neg--;
			count_pos++;
		}
		// ensure sum > 0
		if (count_pos < count_neg) {
			int diff = count_neg - count_pos ;
			operation += diff;
		}

		std::cout << operation << std::endl;
	}

	return 0;
}