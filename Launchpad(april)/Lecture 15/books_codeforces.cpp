# include <iostream>
7.
int main() {
	int n{}, tt{};
	std::cin >> n >> tt;

	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[n];
	}

	int MB = 0; // maximum books that you were able to read
	// Go to every book and treat that book as the starting point.

	for (int s{}; s < n; s++) {
		int tc = 0;
		int cr = 0; // Fromm the book at index s you will be able to read cr books

		for (int e = s; e < n; e++) {
			tc += arr[e];
			if (tc > tt) {
				break;
			}
			cr += 1;
		}
		if (cr > MB) {
			MB = cr;
		}
	}

	std::cout << MB;

	return 0;
}