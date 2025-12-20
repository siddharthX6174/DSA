#include<iostream>
using namespace std;

#define f(a,b) for (int i=a; i<b; i++)

int main() {
	int n;
	cin >> n;
	int a[n];

	f(0, n) {
		cin >> a[i];
	}

	f(0, n) {
		cout << a[i] << " ";
	}
	cout << endl;
}

/*
replaces meaning doesn't allocates memory earlier when the complier runs than the memory is allocated..
it also overseeds everything
*/