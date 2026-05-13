#include<bits/stdc++.h>
using namespace std;

int smallest(vector<int>&arr) {
	int s = arr.size();
	int k = INT_MAX;
	for (int& x : arr) {
		if (x < k) {
			k = x;
		}
	}
	return k;
}

int largest(vector<int>& arr) {
	int k = INT_MIN;
	for (int& x : arr) {
		if (x > k) {
			k = x;
		}
	}
	return k;
}

void reverse(vector<int>& arr) {
	int i = 0, j = arr.size() - 1;
	while (i <= j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
}

int sum(vector<int>& arr) {
	int s{};
	for (int& x : arr) {
		s += x;
	}
	return s;
}

// avg -> sum of element / count then print as double
double avg(vector<int>& arr) {
	int s{};
	for (int& x : arr) {
		s += x;
	}
	return (double) s / arr.size();
}

// insert an element in array
void insrt(vector<int>& arr, int pos) {
	int a{};
	a = 88;
	arr.push_back(a);
	swap(arr[arr.size() - 1], arr[pos - 1]);
}

void print(vector<int>& arr) {
	for (auto x : arr) {
		cout << x << " ";
	}
	cout << "\n";
}

// count frequency
void freq(vector<int>&arr) {
	map<int, int>mp;
	for (auto& x : arr) {
		mp[x]++;
	}

	for (const pair<int, int>& x : mp) {
		cout << x.first << "-->" << x.second << "\n";
	}

	return;
}

void helper(vector<int>& arr, int strt, int end, int k) {
	while (strt <= end) {
		int mid = (strt + end) / 2;
		if (arr[mid] == k) {
			cout << "number found here \n";
			return;
		} else if (arr[mid] < k) {
			strt = mid + 1;
		} else {
			end = mid - 1 ;
		}
	}
	cout << "number not found better luck next time \n";
	return;
}
void binarysearch(vector<int> arr) {
	sort(arr.begin(), arr.end());
	// start
	int strt = 0;
	// end
	int end = arr.size() - 1;
	helper(arr, strt, end, 3);
}

int main() {
	vector<int>arr;
	int a;
	while (cin >> a) {
		arr.push_back(a);
	}

	cout << smallest(arr);
	cout << "\n" << largest(arr) << "\n";

	reverse(arr);
	print(arr);

	cout << sum(arr) << "\n";

	cout << avg(arr) << "\n";

	insrt(arr, 3);
	print(arr);

	freq(arr);

	binarysearch(arr);

	return 0;

}