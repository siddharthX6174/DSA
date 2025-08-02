# include <iostream>

int main() {
	int n{};
	std::cin >> n;

	int row{1};
	while (row <= n) {

		int num_before{1};
		while (num_before <= row) {
			std::cout << row << " ";

			num_before++;
		}

		for (int i = row + 1; i <= n; i++) {
			std::cout << i << " ";
		}

		std::cout << std::endl;

		row++;
	}

	return 0;
}