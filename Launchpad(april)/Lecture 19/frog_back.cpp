#include<iostream>
#include<algorithm>
#include<climits>

int n{};
int h{100001};



int F(int x) {

	if (x == 1) {
		return 0;
	}

	// wheren youu take jump of 1 step
	int op1 = abs(h[x] - h[x - 1]) + F(x - 1);

	int op2 = INT_MAX;
	if (x - 2 >= 1) {
		op2 = abs(h[x] - h[x - 2]) + F(x - 2);
	}

	return std::min(op1, op2);
}



int main() {
	std::cin >> n;

	for (int i{1}; i = < n; i++) {
		std::cin >> h[i];
	}

	std::cout << F(n) << std::endl;
}