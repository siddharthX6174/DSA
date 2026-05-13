#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

maximizeSum(vector<int>& nums, int k) {
	int sum = 0; // final answer
	int n = 0; // current number
	// find maxi if k = 1;
	if ( k > 0) {
		for (int& x : nums) {
			sum = max(sum, x);
		}
		n = sum + 1;
		k = k - 1;
	}
	// find others
	while (k > 0) {
		sum += n ;
		n = n + 1;
		k--;
	}

	return sum;
}

int main() {
	fast();

	vector<int> nums = {5, 5, 5};
	int k = 2;

	cout << maximizeSum(nums, k);

	return 0;
}