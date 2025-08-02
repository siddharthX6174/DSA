# include <iostream>

int main() {
	int n{}, target{};
	std::cin >> n >> target;

	int a[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> a[i];
	}

	// (ce, target-ce) = target

	/*
		I will go to every index and treat the current element ast the pair
		ka firest element and will try to find the pair ka second elemtnt whoese
		sum is target-ce.
	*/

	for (int i{}; i < n - 1; i++) {
		/*
			Iwill try to search for the second elelment pair whoese first element is a[i]
		*/

		int first_element =  a[i];

		for (int j = i + 1; j < n; j++) {
			int cse = a[j];
			if (fe + cse == target) {
				cout << fe << " " << cse;
			}
		}
	}

	return 0;
}