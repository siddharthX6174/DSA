# include <iostream>

int main() {

	int n{};
	std::cin >> n;

	// first half
	int row = 1;
	while (row <= 5) {


		int space{1};
		while (space <= (n - row)) {
			std::cout << "  ";
			space++;
		}


		int star{1};
		while (star <= (2 * row - 1)) {
			std::cout << "* ";
			star++;
		}

		std::cout << std::endl;

		row++;
	}


	// second half

	row = n - 1;
	while (row > 0) {
		int space{1};
		while (space <= n - row) {
			std::cout << "  ";
			space++;
		}

		int star{1};
		while (star <= 2 * row - 1) {
			std::cout << "* ";
			star++;
		}
		std::cout << std::endl;

		row--;
	}

	return 0;

}