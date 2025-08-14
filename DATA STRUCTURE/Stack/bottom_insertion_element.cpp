/*
inserrt the element in the bottomm of the stack using recurison
*/

# include <iostream>
using namespace std;
# include <stack>


void insertBottom(stack<int>&st, int x) {
	if (st.empty()) {
		st.push(x);
		return;
	}

	int temp = st.top();
	st.pop();
	insertBottom(st, x);
	st.push(temp);
}



int main() {
	stack<int> s;

	s.push(8);
	s.push(7);
	s.push(6);
	s.push(5);

	insertBottom(s, 100);

	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}