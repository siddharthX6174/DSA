# include <iostream>
# include <algorithm>

int main() {
	int n{};
	std::cin >> n;
	int arr[200] {};
	for (int i{}; i < n; i++) {std::cin >> arr[i];}

	int i{}, j = n - 1;
	while (i < j) {
		std::swap(arr[i], arr[j]);
		i++;
		j--;
	}

	for (int i{}; i < n; i++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}