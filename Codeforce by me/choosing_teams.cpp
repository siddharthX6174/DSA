# include <iostream>

void Bubble_sort (int arr[], int n) {

	for (int task {0}; task < n - 1; task++) {
		for (int i{0}; i < n - task - 1; i++) {
			if (arr[i] > arr[i + 1] ) {
				std::swap(arr[i], arr[i + 1]);

			}
		}
	}

}

int main() {
	int n{}; // no of students
	int k{}; // how many times each team should participate
	std::cin >> n >> k;
	int arr[n] {};
	for (int i{}; i < n; i++) {
		std::cin >> arr[i];
	}

	Bubble_sort(arr, n);

	int student_elegible{};
	for (int i{}; i < n; i++) {
		if (arr[i] <= (5 - k)) {
			student_elegible++;
		}
	}

	int teams = student_elegible / 3;

	std::cout << teams << std::endl;

	return 0;
}