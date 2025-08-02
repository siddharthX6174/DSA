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





	// Resoltvinf the first range:
	// Iamd finding out konsa operration kiiti bar karna hai.

	int oc[100001] {};
	for (int i{1}; i <= k; i++) {
		int x{}, y{};
		std::cin >> x >> y;

		/*
			Formulae:
			d[l] = task
			d[r+1] = opposite task

			and do this for every query and then take prefix sum.
		*/

		oc[x] += 1;
		oc[y + 1] -= 1;

		for (int i = 1; i <= 10001; i += 1) {
			oc [i] = oc[i - 1] + oc[i];
		}


		// Resolving the sescond range.
		// I am going to every ooperation and directly resolving the value

		int difference[100001] {};
		for (int i{1}; i < 100001; i += 1) {
			/*
				current operation ko perform karne ka new matalb hain:
				l[i] se lekar r[i] tak aapko
				ab (d[i] * oc[i]) ko add karna hain.

				use the formulae:
			*/

			int left = l[i];
			int right = r[i];

			difference[left] += (d[i] * oc[i]);
			difference[right + 1] -= ((d[i] * oc[i]));
		}

		for (int i{1}; i <= 100001; i++) {
			difference[i] = difference[i - 1] + difference[i];
		}

		// add in the orignial array:
		for (int i = 1; i <= n; i += 1) {
			std::cout << a[i] + difference[i];
		}
	}






	for (int i{1}; i <= n; i++) {
		std::cout << a[i] << " ";
	}

	return 0;

}