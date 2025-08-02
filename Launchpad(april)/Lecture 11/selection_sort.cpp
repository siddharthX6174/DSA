# include <iostream>
# include <algorithm>

void selection_sort (int arr[], int n) {


	//logic for selectionn sort
	for (int k{}; k < n - 1; k++) {
		int mini = k;

		// we need to find the minimumm accorfing to task number
		for (int i{k + 1}; i < n; i++) {
			if (arr[i] < arr[mini]) {
				mini = i;
			}
		}

		// We now have the current minimmum element .
		// I want to swap minimum element with the task number index element

		std::swap(arr[k], arr[mini]);
	}

}

int main() {
	int n{};
	std::cin >> n;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	if (n > 1) {
		selection_sort(arr, n);
	}

	for (int i{}; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}


/*
	swap two numberes
	int a=10, b=20;

	int temp = a;
	a = b;
	b = temp;

*/