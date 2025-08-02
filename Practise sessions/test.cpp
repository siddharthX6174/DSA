# include <iostream>
# include <algorithm>

int n{}, h{}, l{}, r{};
int a[20001];

int F(int index, int waking_time) {

	// base case
	if (index == n) {
		return 0;
	}

	//----------------------------------------------------------------
	// ky meri sleep good hai ??
	// current sleep for a[i]   is godd or not ?
	int x = (waking_time + a[index]) % h; // sleep time
	int ans1{};
	if (l <= x and x <= r) {
		ans1 = 1;
	}


	// for the sleep a[i] - 1

	int y = (waking_time + a[index] - 1) % h;
	int ans2{};
	if (l <= y and y <= r) {
		ans2 = 1;
	}
	//----------------------------------------------------------------

	// for the sleep after a[i] hours
	int op1 = ans1 + F(index + 1, x);

	int op2 = ans2 + F(index + 1, y);

	return std::max(op1, op2);
	//return op1 + op2;


}



int main() {
	std::cin >> n >> h >> l >> r;
	for (int i{}; i < n; i++) {
		std::cin >> a[i];
	}

	std::cout << F(0, 0) << std::endl;

}