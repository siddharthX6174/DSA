#include <iostream>
using namespace std;
#include <stack>

/*
 inserting a new element into an already sorted stack (without breaking its
 sorted order).
 “Sorted Insertion in a Stack” and can be done using recursion

Example
Stack (top → bottom): 1 3 5 8
Insert: 4
Output Stack (top → bottom): 1 3 4 5 8

Approach (Recursive)
Base case

If stack is empty OR x is greater than the top element (for ascending order), push x.

Recursive step

Otherwise, pop the top, recursively insert x in the remaining stack, then push the popped element back.
*/


void sortedinsert(stack<int> &st, int x) {
	// Base case: stack is empty OR element to insert is greater than top element
	if (st.empty() || x < st.top()) {
		st.push(x);
		return;
	}

	int temp = st.top();
	st.pop();
	sortedinsert(st, x);
	st.push(temp);
}


int main() {
	stack<int> st;

	// Bottom → Top: 8 5 3 1  (top is 1)
	st.push(8);
	st.push(5);
	st.push(3);
	st.push(1);

	int x;
	cin >> x;

	sortedinsert(st, x);

	// Printing stack from top to bottom
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}

