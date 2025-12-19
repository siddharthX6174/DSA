#include<iostream>
using namespace std;
/*
	to use stl algorithms u need to use #include<algorithm>
	1) sort
	2) reverse
	3) binary_search
	4) lower_bound
	5) upper_bound

	there are some algos which are container specifics:
	6) Find
	7) count
*/
#include<algorithm>

// Comparator can only return true and false
// This is telling my algorithm that how we want the comparison between two elements while
// performing the current algorithm

bool compare(int x, int y) {
	// jo element phle ana chiye woh  -> x (first argument)
	// jo baad m ana chiye -> y (second argument)

	/*
		if your function return true then u tell the algorithm that the current positioning of the
		elements is correct and u donot have to do anything.
	*/

	/*
		if your function returns false then you tell the algorithm that current positioning of the
		elements is not correct and u have to swap the elements (u tell this to the compiler.)
	*/

	/*
		since we are sorting this array in descending order.
	*/

	if (x > y) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int a[] {11, 2, 13, 14, 5, 16, 7};
	int n = 7;

	sort(a, a + n); // (tim , insertion, heap -> sort)

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	// Compartors:
	// now u want to sort this array in descending order.

	sort (a, a + n, compare);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;


	// sort(a, a + n, false);
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;


	/*
		in case of string we can't use pointers so we use iterators
		s.begin() -> returns the addess of first block
		s.end() -> returns the address of (last block + 1)

		container adapter k alwa hum iterators se use krte hai..
	*/

	int k[] {1, 2, 3, 3, 3, 3, 4, 5, 6, 7};
	cout << binary_search(k, k + n, 7) << endl;

	/*
		lower bound and upper bound in stl return the address in case of ds and in case of
		containers they return iterator that means if you are using lower and upper bound on ds like
		array you can print the address very easily just by printing lower and upper bound but in case
		of container you will not be able to print the upper and lower bound direclty as u cannot print
		the iterators..
	*/

	cout << lower_bound(k, k + 10, 3) << endl;
	// i want index

	int index = lower_bound(k, k + 10, 3) - k;
	cout << index << endl;

	// count freq of 3

	cout << (upper_bound(k, k + 10, 3) - k) - (lower_bound(k, k + 10, 3) - k) << endl;


}
