#include <iostream>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// int F(int n) {
// 	if (n == 1) return 0;
// 	if (n == 2) return 1;
// 	return (F(n - 1) + F(n - 2));
// }


int main() {
	fast();

	int n;
	cin >> n;
	int dp[n + 1] {};

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] ;

	return 0;
}