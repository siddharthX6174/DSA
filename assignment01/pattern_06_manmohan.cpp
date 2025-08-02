# include <iostream>

int main() {
	int n{};
	std::cin >> n;

	int row{1};
	while (row <= n) {

		if (row % 2 == 0) {

			int j = 1;
			while (j <= row) {
				if (j == 1 or j == row) {
					std::cout << 1;
				} else {
					std::cout << 0;
				}
				j++;
			}

		}

		else {
			int i = 1;
			while (i <= row) {
				std::cout << 1;
				i++;
			}
		}

		std::cout << std::endl;

		row++;
	}

	return 0;
}