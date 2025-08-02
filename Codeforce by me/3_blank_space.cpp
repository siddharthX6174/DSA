# include <iostream>
# include <algorithm>

int main() {
	int t{};
	std::cin >> t;

	while (t--) {
		int n{};
		std::cin >> n;
		int a{};
		int max_blank{}, current_blank{};

		while (n--) {
			std::cin >> a;

			if (a == 0) {
				current_blank++;
				max_blank = std::max (max_blank, current_blank);
			} else {
				current_blank = 0;
			}
		}

		std::cout << max_blank << std::endl;
	}

	return 0;
}