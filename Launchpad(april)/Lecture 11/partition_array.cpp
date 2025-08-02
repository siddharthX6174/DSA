# include <iostream>
#include <algorithm>

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	int maxi{arr[0]};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
		maxi = std::max(maxi, arr[i]);
	}

	int freq[maxi + 1] {};
	for (int i{}; i < n; i++) {
		int ce = arr[i];
		freq [ce]++;
	}




	int count{}, ans{};
	for (int i{}; i < maxi + 1; i++) {
		if (freq[i] > 0) {
			count++;
			if (count % 2 != 0) {
				ans +=  i;
			}
		}
	}

	std::cout << ans << std::endl;
	return 0;
}