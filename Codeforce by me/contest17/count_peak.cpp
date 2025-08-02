// # include <iostream>


// int main() {
// 	int t{};
// 	std::cin >> t;
// 	while (t--) {

// 		int n{};
// 		std::cin >> n;

// 		int k{};
// 		std::cin >> k;

// 		int arr[n] {};

// 		for (int i{}; i<n; i++) {
// 			std::cin >> arr[i];
// 		}

// 		int count_preak{};

// 		for (int i{}; i<n; i++) {
// 			int d{};
// 			if (arr[i] == 0) {
// 				d++;
// 			}else{
// 				d=0;
// 			}

// 			if (d== k) {
// 				i++;
// 				count_preak++;
// 			}

// 		}

// 		std::cout << count_preak;
// 	}

// 	return 0;
//

#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> arr(n);

		for (int i = 0; i < n; ++i) {
			std::cin >> arr[i];
		}

		int count_hikes = 0;
		int i = 0;

		while (i <= n - k) {
			bool can_hike = true;

			for (int j = 0; j < k; ++j) {
				if (arr[i + j] != 0) {
					can_hike = false;
					break;
				}
			}

			if (can_hike) {
				count_hikes++;
				i += k + 1;  // Skip k days of hiking and 1 day of break
			} else {
				i++;
			}
		}

		std::cout << count_hikes << "\n";
	}

	return 0;
}
