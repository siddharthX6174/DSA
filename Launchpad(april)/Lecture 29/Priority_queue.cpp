#include<iostream>
#include<queue>
using namespace std;


/*
	Priority_Queue: Heaps (Tree Based DSA):
	Priority set kardete hain in a queue.

	Large/Small


	Tree Like Structure:
	Priority: largest:
	Largest element will always be visible at the top and if
	you remove the largest element a process name
	as heapify goes on and in this process my data
	is again rearranged and the new maximum will
	again be visible at the top.
*/

//This is a max priority queue : Largest
priority_queue<int>pq;

//This is a min Priority queue: Smallest
priority_queue<int, vector<int>, greater<int>>mpq;


int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
		mpq.push(x);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << endl;

	while (!mpq.empty()) {
		cout << mpq.top() << " ";
		mpq.pop();
	}



}