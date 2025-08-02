#include<iostream>
using  namespace std;



/*
	Print All the subarrays and Its count.

	1. We are print the subarray based on index.

	H.W.
	Print the subarray based on size.


	3 1 4 2 8

	We want to print the subarray based on index.


	1. We want to print all the subarrays that start
	   from 0 index.

	   and so on!....

	3
	3 1
	3 1 4
	3 2 4 2
	3 1 4 2 8

	1
	1 4
	1 4 2
	1 4 2 8

	4
	4 2
	4 2 8

	2
	2 8

	8

	Total Subarray count = 15;


	Idea : I will go to every index and do some task.


	Task: Print ??? Current subarray and then all the subarray
	jo is index se start hote hain.

	Currently we are at 0 index which serves as the starting
	point for the current subarray.

	Ending Point : 0,1,2,3,4

	SP: 1
	EP: 1,2,3,4

	SP : 2
	EP : 2,3,4

*/

int main() {

	int n;
	cin >> n;

	int a[n] {0};

	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}

	int maxi = INT_MIN;//Maximum subarray sum

	for (int s = 0; s < n; s += 1) {

		//Current Starting Point is s.

		//For my current starting Point I have multiple
		//ending points.

		for (int e = s; e < n; e += 1) {
			//Current Subarray is from range [s,e].
			//Print the current subarray.
			int sum = 0;

			for (int k = s; k <= e; k += 1) {
				sum += a[k];
				//cout << a[k] << " ";
			}

			cout << sum;//THis is current subarray sum.

			if (maxi < sum) {
				maxi = sum;//Update if current subarray sum is greater than the maximum subarray sum.
			}

			cout << endl;
		}
	}
}