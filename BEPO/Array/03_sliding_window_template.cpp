#include <iostream>
using namespace std;

int main() {

	int ans;
	int windowValue;
	int k; // window size

	for (int i = 0; i < n; i++) {

		// add the elements
		windowValue += nums[i];

		// remove if window exceeds
		if (i >= k) {
			windowValue -= nums[i - k];
		}

		if (i >= k - 1) { // window size == k
			ans = max(ans, windowValue);
		}
	}
}