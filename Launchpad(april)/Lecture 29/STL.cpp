#include<iostream>
#include<list>
#include<stack>
#include<queue>

using namespace std;

/*
	forward_list : Singly Linked List
	list : Doubly Linked List

	vector
	list
*/

list<int>F() {

}

int main() {

	int n;
	cin >> n;

	forward_list<int>f;
	list<int>l, l1;
	stack<int>s;
	queue<int>q;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		f.push_front(x);
		l.push_front(x);
		l.push_back(x);
		s.push(x);
		q.push(x);
	}


	f.pop_front();
	l.pop_front();
	l.pop_back();

	l1 = l;

	Solve(l);
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << (*it) << endl;
	}

	for (int x : l) {
		cout << x << " ";
	}


	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	while (!q.empty()) {
		cout << q.front() << " ";
		s.pop();
	}

}