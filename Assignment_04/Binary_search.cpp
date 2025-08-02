# include <iostream>

int Binary_Search (int arr[], int n, int target) {
	int start{}, end{n - 1};
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {start = mid + 1;}
		else end = mid - 1;
	}
	return -1;
}

int main () {
	int n{};
	std::cin >> n;
	int arr[100] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}
	int target{};
	std::cin >> target;

	int index = Binary_Search(arr, n, target);
	std::cout << index << std::endl;

	return 0;
}