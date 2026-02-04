#include<bits/stdc++.h>
#include<thread>
using namespace std;

void add(int &sum, int s, int e) {
	int localSum = 0;   // each thread local
	for (int i = s; i < e; i++) {
		localSum += i;
	}
	sum = localSum;     // write once only
}

int main() {
	int s = 0, e = 100000;
	int finalSum = 0;

	add(finalSum, s, e);

	// int sum1 = 0, sum2 = 0, sum3 = 0;

	// thread t1(add, ref(sum1), s, e / 3);
	// thread t2(add, ref(sum2), e / 3, 2 * e / 3);
	// thread t3(add, ref(sum3), 2 * e / 3, e);


	// t1.join();
	// t2.join();
	// t3.join();

	// int finalSum = sum1 + sum2 + sum3;

	cout << finalSum << endl;
}
