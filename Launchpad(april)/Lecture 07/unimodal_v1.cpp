#include<iostream>
using  namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	int b[n];

	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i += 1) {

		if (a[i] > a[i - 1]) {
			b[i] = 0;//Increasing
		} else if (a[i] == a[i - 1]) {
			b[i] = 1;//Constant
		} else {
			b[i] = 2;//Decreasing
		}
	}


	for (int i = 2; i < n; i += 1) {
		if (b[i] < b[i - 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

}