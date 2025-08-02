# include <iostream>

int main() {
	int n{}; // size of the array
	std::cin >> n;
	int a[n] {};
	for (int i{}; i < n; i++) {std::cin >> a[i];}

	int zero_count{};
	for (int i{}; i < n; i++) {
		if (a[i] == 0) {
			zero_count++;
		}

	}

	// 0 filling
	for (int i{0}; i < zero_count; i++) {
		a[i] = 0;
	}

	// 1 fillinng
	for (int i{zero_count}; i < n; i++) {
		a[i] = 1;
	}

	// answer output
	for (int i{}; i < n; i++) {
		std::cout << a[i] << " ";
	}


	return 0;
}