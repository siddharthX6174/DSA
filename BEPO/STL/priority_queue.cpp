#include<bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> pq; // max priority queue
	priority_queue<int, vector<int>, greater<int>> mpq; // min priority queue

	int x;
	while (cin >> x) {
		pq.push(x);
		mpq.push(x);
	}

	cout << pq.size() << "\n";

	while (pq.empty() != true) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << "\n";
	while (mpq.empty() != true) {
		cout << mpq.top() << " ";
		mpq.pop();
	}

	return 0;
}