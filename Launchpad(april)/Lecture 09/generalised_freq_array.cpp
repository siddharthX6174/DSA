# include <iostream>
# include <climits>

/*
	Limitaitons of freq array:
	Since you cannot create aan local/fuctional scoope array of 10^5/10^6 you will not be able to

*/

int main() {
	int n{};
	std::cin >> n;
	int a[n] {};

	int maxi{INT_MIN};
	int mini{INT_MAX};

	for (int i{}; i < n; i++) {
		std::cin >> arr[i];

		// For maximum value
		if (maxi > a[i]) {
			maxi = a[i];
		}
		// for mini vlue
		if (mini < a[i]) {mini = a[i];}
	}

	int freq [maxi - mini + 1] {};

	// Buildinnng of the frea array

	for (int i{}; i < n; i++) {
		//int ce = a[i];
		freq[a[i] - mini]++;
	}

	std::cout << "Element : Frequency\n";
	for (int i = 0; i < range; i++) {
		if (freq[i] > 0) {
			std::cout << (i + mini) << " : " << freq[i] << "\n";
		}
	}


}