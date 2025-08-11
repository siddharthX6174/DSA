#include<iostream>
#include<iomanip>
#include<climits>
#include<cstring>
using namespace std;
#define MAX 1000

template<typename T>
class Stack {
public:
	T a[MAX];
	T topofstack;//This is working as index in array a.


	Stack() {
		memset(a, 0, sizeof(a));
		topofstack = -1;
	}

	void push(T x) {

		if (topofstack >= MAX - 1) {
			cout << "Stack Overflow" << endl;
			return;
		}

		topofstack++;
		a[topofstack] = x;
		return;
	}

	bool empty() {
		if (topofstack == -1) {
			return 1;
		} else {
			return 0;
		}
	}

	void pop() {
		if (topofstack == -1) {
			return;
		}
		topofstack--;
	}

	T top() {
		if (topofstack == -1) {
			return -1;
		} else {
			return a[topofstack];
		}
	}
};

