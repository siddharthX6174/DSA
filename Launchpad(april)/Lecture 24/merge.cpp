#include<iostream>
using namespace std;
int a[1001];
int n;


void merge(int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;

	int temp[1001] {};
	int k = s; // This is to iterate over the third array.


	// compare and merge;
	while (i <= mid and j <= e) {
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			i++;
			k++;
		} else {
			temp[k] = a[j];
			j++;
			k++;
		}
	}

	// what if i  have still not reached the end or i from above loop

	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= e) {
		temp[k] = a[j];
		k++;
		j++;
	}


	// copy the content of the temp array to the original array

	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}
}



// divide the range till you can by mid point.
void mergesort(int s, int e) {

	if (s >= e) {
		return;
	}

	int mid = (s + e) / 2;
	mergesort(s, mid);
	mergesort(mid + 1, e);

	// Task ;
	merge(s, e);
	return;
}

int main() {
	cin >> n;
	for (int i{}; i < n; i++) {
		cin >> a[i];
	}

	mergesort(0, n - 1);

	for (int i{}; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}