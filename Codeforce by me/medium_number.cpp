// from threee elements print the niether min nor max number

# include <iostream>
# include <climits>

int main() {
	int t{};
	std::cin >> t;

	while (t--) {
		int arr[3] {};
		for (int i{}; i < 3; i++) {
			std::cin >> arr[i];
		}

		int mini = INT_MAX;
		int maxi = INT_MIN;

		for (int i{}; i < 3; i++) {
			if (arr[i] < mini) {
				mini = arr[i];
			}
			if (arr[i] > maxi) {
				maxi = arr[i];
			}
		}

		for (int i{}; i < 3; i++) {
			if (arr[i] != mini && arr[i] != maxi) {
				std::cout << arr[i] << std::endl;
			}
		}
	}

	return 0;
}