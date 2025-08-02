#include<iostream>
#include<cstring>
const int N = 1000007;

int n{};
int value[N] {};
int visited[N] {};
int min_steps = INT_MAX; // minimum stesps accross  all the paths.

void F(int i, int count) {

	if (i == n) {
		min_steps = std::min(min_steps, count);
		return;
	}

	visited[i] = 1;

	// op1: Whwn you take one step jump.
	if (i + 1 <= n and visited[i + 1] == 0) {
		F(i + 1, count + 1);
	}

	// op2 : when you take value[i] step jump.
	if (i + value[i] <= n  and i + value[i] >= 0 and visited[i + value[i]] == 0) {
		F(i + value[i], count + 1);
	}

	// If you are standing here that means recursion has already calculated the min steps
	// from the ith stair and you are returning form the ith stair than you would want to make
	/// this stair avaialbel for future paths
	visited[i] = 0; // backtracking

	return;
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		std::cin >> n;
		for (int i{}; i < n; i++) {
			std::cin >> value[i];
		}

		memset(visited, 0, sizeof(visited));  // it can initialize container with values 0,-1,1.

		//min_steps = INT_MAX;  // FIX: Reset for each test case

		F(0, 0);

		if (min_steps == INT_MAX)
			std::cout << -1 << std::endl;
		else
			std::cout << min_steps << std::endl;

		min_steps = INT_MAX;
	}


}