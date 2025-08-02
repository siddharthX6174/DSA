# include <iostream>

int main() {
	int n{};
	std::cin >> n;

	int row{1};
	while (row <= n) {

		int space{1};
		while (space <= (n - row)) {
			std::cout << "  ";
			space++;
		}

		int num_incr{row};
		while (num_incr <= (row + (row - 1))) {
			std::cout << num_incr << " ";
			num_incr++;
		}

		int num_decr = (row + (row - 1)) - 1;
		while (num_decr >= row) {
			std::cout << num_decr << " ";
			num_decr--;
		}

		std::cout << std::endl;


		row++;
	}

	return 0;
}