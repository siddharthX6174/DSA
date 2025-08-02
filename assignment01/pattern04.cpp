# include <iostream>

int main() {
	int n{};
	std::cin >> n;

	int row{1};
	while (row <= n) {

		std::cout << row << " ";

		int zero_count{1};
		while (zero_count <= (row - 2)) {
			std::cout << 0 << " ";
			zero_count++;
		}

		if (row  > 1) {
			std::cout << row << " ";
		}

		std::cout << std::endl;

		row++;
	}

	return 0;
}