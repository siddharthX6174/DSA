# include <iostream>
# include <algorithm>

int Binary_V2 (int arr[], int start, int end, int target) {
	end--;
	int ans{};
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] <= target) {
			ans = mid + 1;
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return ans;
}





int main() {
	int n{};
	std::cin >> n;
	int bottle_price [n] {};
	for (int i{}; i < n; i++) {
		std::cin >> bottle_price[i];
	}
	std::sort(bottle_price, bottle_price + n);

	int days{};
	std::cin >> days;

	int coin{}, output{};
	for (int i{}; i < days; i++) {
		std::cin >> coin;
		output = Binary_V2(bottle_price, 0, n, coin);
		std::cout << output << std::endl;
	}

	return 0;
}