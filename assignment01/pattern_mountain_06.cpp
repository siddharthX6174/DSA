# include <iostream>

int main() {
	int n{};
	std::cin >> n;

	int row{1};
	while (row <= n) {

		int num_before{1};
		while (num_before <= row) {
			std::cout << num_before << " ";
			num_before++;
		}

		if (row < n) {
			int space{1};
			while (space <= ((n - row) + ((n - row) - 1)) ) {
				std::cout << "  ";
				space++;
			}

			int num_after{row};
			while (num_after >= 1) {
				std::cout << num_after << " ";
				num_after--;
			}
		} else {
			int num_after{n - 1};
			while (num_after > 0) {
				std::cout << num_after << " ";
				num_after--;
			}
		}

		std::cout << std::endl;

		row++;
	}
	return 0;

}