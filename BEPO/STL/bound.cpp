/*
	find first element that is greater than or equal to 3
	1,1,1,3,3,3,3,3,5,7,9
	x=3 -> ans=3
	x=4 -> ans=5

	agar mid bda hai key se toh possible answer hai and tum left move karoge
*/

/*
	upper bound -> first element that is > x

	freq of 3 -> idx (upper bound - lower bound)
*/

#include<iostream>
using namespace std;

int main() {
	int a[10] {1, 1, 1, 3, 3, 3, 3, 5, 7, 9};

	int start = 0, end = 9;

	int key = 4;

	int ans = -1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (a[mid] >= key) {
			ans = a[mid];
			end = mid - 1 ;
		} else {
			start = mid + 1;
		}
	}

	cout << ans << endl;
}