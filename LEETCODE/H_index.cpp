# include <iostream>
# include <algorithm>
# include <climits>

int main() {
	int citations [] {1, 3, 1};
	int n = std::size(citations);

	int maxi = INT_MIN;
	for (int i{}; i < n; i++) {
		maxi = std::max(maxi, citations[i]);
	}

	int freq[maxi + 1] {};
	for (int i{}; i < n; i++) {
		freq[citations[i]]++;
	}

	int pre[maxi + 1] {};
	pre[0] = citations[0];
	for (int i{1}; i < maxi + 1; i++) {
		pre[i] = pre[i - 1] + freq[i];
	}

	int h {}; // requires h-index
	for (int i{1}; i < maxi + 1; i++) {
		if (pre[maxi] - pre[i - 1] >= i) {
			h = i;
		}
	}

	std::cout << h << std::endl;
	return 0;
}