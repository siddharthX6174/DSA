# include <iostream>

int main () {
	int n{};
	std::cin >> n;

	int row{1};
	while (row <= n) {

		int num{1};
		while (num <= row) {
			std::cout << num;
			num++;
		}

		int star{n - row};
		while (star--) {
			std::cout << "*";
		}

		std::cout << std::endl;

		row++;
	}

	return 0;

}