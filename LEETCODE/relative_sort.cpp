#include <iostream>
#include <algorithm>
#include <climits>

int main() {
	int arr1[] {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
	int arr2[] {2, 1, 4, 3, 9, 6};
	int n = std::size(arr1);
	int m = std::size(arr2);

	int maxi_2 = INT_MIN;
	for (int i = 0; i < m; i++) {
		maxi_2 = std::max(maxi_2, arr2[i]);
	}

	int freq_arr2[maxi_2 + 1] {};
	for (int i = 0; i < m; i++) {
		freq_arr2[arr2[i]]++;
	}

	// two pointer
	int L = 0, R = n - 1;
	while (L <= R) {
		int k = arr1[L];

		if (k <= maxi_2 && freq_arr2[k] > 0) {
			L++;
		} else {
			std::swap(arr1[L], arr1[R]);
			R--;
		}
	}

	int new_n = L;
	int new_arr1_maxi = INT_MIN;
	for (int i = 0; i < new_n; i++) {
		new_arr1_maxi = std::max(new_arr1_maxi, arr1[i]);
	}

	int relative_freq_arr1[new_arr1_maxi + 1] {};
	for (int i = 0; i < new_n; i++) {
		relative_freq_arr1[arr1[i]]++;
	}

	int idx = 0;
	for (int i = 0; i < m; i++) {
		int val = arr2[i];
		while (relative_freq_arr1[val]-- > 0) {
			arr1[idx++] = val;
		}
	}

	// sort remaining part
	std::sort(arr1 + new_n, arr1 + n);

	for (int i = 0; i < n; i++) {
		std::cout << arr1[i] << " ";
	}

	return 0;
}
