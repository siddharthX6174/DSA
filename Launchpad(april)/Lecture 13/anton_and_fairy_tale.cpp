# include <iostream>

long long int Binary_V2 (int n, int m) {
	long long double start = 0, long long double end = 1e10;
	int ans {};
	while (start <= end) {
		long long int mid = start + (end - start) / 2;
		long long int k = mid * (mid + 1) / 2;
		if (k >= (n - m)) {
			ans = k;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return ans;
}

int main() {

	int n{}, m{};
	std::cin >> n >> m;

	if (m >= n) {
		std::cout << n << std::endl;
		return 0;
	}

	int some_var = Binary_V2(n, m);

	std::cout << (m + some_var) << std::endl;


	return 0;
}