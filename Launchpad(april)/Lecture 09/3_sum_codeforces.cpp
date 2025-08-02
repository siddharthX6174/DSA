#include<iostream>
# include <cstdint>
using  namespace std;
#define int long long

// int : 10 ^ 9
// long / long int : 10 ^ 12
// long long / long long int : 10 ^ 18

//Computations : n*n*n*t; 30*30*30*1000 =  (27*10^6).

int32_t main() {
	int t;
	cin >> t;

	while (t > 0) {
		int n;
		cin >> n;
		long long a[n];
		int freq[10] {0};

		for (int i = 0; i < n; i += 1) {
			cin >> a[i];
			a[i] %= 10;//Changed
			int ld = a[i] % 10;
			freq[ld] += 1;
		}

		for (int i = 0; i < 10; i += 1) {
			if (freq[i] > 3) {
				freq[i] = 3;
			}
		}

		//From this freq array create last digit array
		//whose maximum size can be of 30.

		int ld[30] {0};
		int size = 0;//Abhi tak maine ld me kitne elements daal diye hain.


		//From the freq array create ld array.
		for (int i = 0; i < 10; i += 1) {
			int ce = i;
			int f = freq[i];
			while (f > 0) {
				ld[size] = ce;
				size += 1;
				f -= 1;
			}
		}

		int f1 = 0;

		for (int i = 0; i < size - 2; i += 1) {
			for (int j = i + 1; j < size - 1; j += 1) {
				for (int k = j + 1; k < size; k += 1) {
					long long sum = ld[i] + ld[j] + ld[k];
					if ((sum) % 10 == 3) {
						f1 = 1;
						cout << "YES" << endl;
						break;
					}
				}
				if (f1 == 1) {
					break;
				}
			}

			if (f1 == 1) {
				break;
			}
		}

		if (f1 == 0) {
			cout << "NO" << endl;
		}
		t -= 1;
	}
}