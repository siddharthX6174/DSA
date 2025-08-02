# include <iostream>

int main() {
	int n{};
	std::cin >> n;

	int i{1};

	int row{1};

	while (row <= n) {

		int num_count{1};
		while (num_count <= row) {
			std::cout << i << " ";
			i++;
			num_count++;
		}

		std::cout << std::endl;

		row++;
	}

	return 0;
}
