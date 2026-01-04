#include<bits/stdc++.h>
using namespace std;

int main() {
	queue<int>q;
	int x;
	while (cin >> x) {
		q.push(x);
	}

	while (q.empty() != true) {
		cout << q.front() << " ";
		q.pop();
	}

	cout << q.size();
	return 0;
}