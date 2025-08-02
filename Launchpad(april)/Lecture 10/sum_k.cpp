#include<iostream>
#include<climits>
using  namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	//Create prefix array.

	int pre[n + 1] {0};
	pre[0] = a[0];

	int maxi = INT_MIN;
	int mini = INT_MAX;

	for (int i = 1; i < n; i += 1) {
		pre[i] = pre[i - 1] + a[i];
		if (pre[i] > maxi) {
			maxi = pre[i];
		}

		if (mini > pre[i]) {
			mini = pre[i];
		}
	}



	//THis is a frequency array based on prefix array.
	int freq[maxi - mini + 1] {0};

	for (int i = 0; i < n; i += 1) {

		int ce = pre[i];
		if (ce == k) {
			cout << "YES" << endl;
			return 0;
		}

		/*
			Maine ce element tak saare element ki
			frequency update kardi hain.

			Idea:
			1. Har element par jaake pehle ye check karo kiu
			ye current element of prefix array k to nahi
			hain.

			2. freq[ce-k]>0


		*/

		if (((ce - k) > 0) and freq[ce - k] > 0) {
			cout << "YES" << endl;
			return 0;
		}

		freq[ce] += 1;
	}


	//I am standing here.
	cout << "NO" << endl;

}