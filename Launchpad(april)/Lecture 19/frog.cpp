#include<iostream>
#include<climits>





int n{};
int h{100001};

int F(int x) {

	// I take 1 step jump:
	int op1 = abs(h[x] - h[x + 1]) + F(x + 1);

	int op2 = INT_MAX;
	if (x + 2 <= n) {
		OP2 = abs(h[x] - h[x + 2]) + f(x + 2);
	}

	return std::min(op1, op2);
}




int main() {

	std::cin >> n;

	for (int i{1}; i = < n; i++) {
		std::cin >> h[i];
	}

	std::cout << F(1) << std::endl;
}