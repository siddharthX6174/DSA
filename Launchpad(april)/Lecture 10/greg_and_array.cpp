#include<iostream>


int main() {
	int n{}, m{}, k{};
	std::cin >> n >> m >> k;

	// i will be using the one based indexing
	int a[100001] {};
	for (int i {1}; i <= n; i++) {
		std::cin >> a[i];
	}

	// My operatin i will look like thi :
	// l[i] to r[i] add d[i]
	int l[100001] {}, r[100001] {}, d[100001] {};
	for (int i {1}; i <= m; i++) {
		std::cin >> l[i] >> r[i] >> d[i];
	}

	while (k > 0) {

		/*
			My cuurent query means : Perform operations from x to y
			This means you have to perform :
			operation number x, x+1, x+2 _ _ _ _ _ _ y..
		*/

		int x{}, y{};
		std::cin >> x >> y;

		for (int j = x; j <= y; j++) {

			/*
				I am trying to perform operiatin number j.
				To perform jth operatiojjn you have to add d[j] t0 array a from index l[j] to r[j].
			*/

			for (int k = l[j]; k <= r[j]; k++) {
				a[k] += d[j];
			}

		}

		k -= 1;
	}

	for (int i{1}; i <= n; i++) {
		std::cout << a[i] << " ";
	}

	return 0;

}