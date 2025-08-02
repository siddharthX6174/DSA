#include<iostream>
# include <algorithm>

int main() {
	int n{};
	std::cin >> n;
	int arr[n];
	// height of the array
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	int left{}, right = n - 1, area{};

	while (left < right) {
		int cw = right - left;
		// int ch = arr[left];
		// if (arr[left] > arr[right]) {
		// 	ch = arr[right];
		// }
		int ch = std::min(arr[left], arr[right]);

		int ca = cw * ch;
		if (area < ca) {
			area = ca;
		}
		if (arr[left] > arr[right]) {
			right --;
		} else {
			left ++;
		}
	}

	std::cout << area;
	return 0;
}