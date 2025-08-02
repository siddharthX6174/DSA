// check if the array is sorted or not !!

# include <iostream>
# include <vector>
using namespace std;

vector<int> arr = {1, 2, 3, 899, 5};

bool is_sorted (int n) {
	if (n == 0 or n == 1) {
		return true;
	}

	return ( (arr[n - 1] >= arr[n - 2]) and (is_sorted(n - 1)));
}



int main() {

	cout << is_sorted(5);

	return 0;
}