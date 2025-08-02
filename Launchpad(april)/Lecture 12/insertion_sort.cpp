#include<iostream>


int main() {
	int n{};
	std::cin >> n;
	int a[n] {};
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}


	// Insetion sort algo
	for (int i{1}; i < n; i++) {
		int ce = a[i];


		int j = i - 1;
		while ((j >= 0) and (a[j] > ce)) {
			// piche jao and shift karte jao
			a[j + 1] = a[j];
			j -= 1;
		}

		// if i am here that mean either i have smaller elememt or j<0 put the ce

		a[j + 1] = ce;
	}


	for (int i{}; i < n; i++) {
		std::cout << a[i] << " ";
	}

	return 0;
}