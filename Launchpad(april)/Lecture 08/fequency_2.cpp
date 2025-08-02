# include <iostream>
# include <climits>

int main() {
	int n{};
	std::cin >> n;

	int a[n] {};

	int maxi = INT_MIN;
	for (int i{}; i < n; i++) {
		std::cin >> a[i];
		if (maxi < a[i]) {
			maxi = a[i];
		}
	}

	int freq[maxi + 1] {};

	for (int i{}; i < n; i++) {
		int ce = a[i];
		freq[ce]++;
	}

	// Print the freq array:

	for (int i{}; i <= maxi; i++) {
		if (freq[i] > 0) {
			std::cout << i << " " << freq[i] << std::endl;
		}
	}

}