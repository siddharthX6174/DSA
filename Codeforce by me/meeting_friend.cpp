# include <iostream>
# include <algorithm>
# include <climits>

int main() {
	int arr[3] {};
	int maxi{INT_MIN};
	for (int i{}; i < 3; i++) {
		std::cin >> arr[i];
		maxi = std::max(maxi, arr[i]);
	}
	int freq_arr[maxi + 1] {};
	for (int i{}; i < 3; i++) {
		int ce = arr[i];
		freq_arr[ce]++;
	}

	int index = 0;
	for (int i = 0; i <= maxi; i++) {
		while (freq_arr[i] > 0) {
			arr[index++] = i;
			freq_arr[i]--;
		}
	}


	int meeting_point = arr[1];
	int total_distance = (meeting_point - arr[0]) + (arr[2] - meeting_point);
	std::cout << total_distance;
	return 0;
}