/*
reverse the stack
*/
# include <iostream>
using namespace std;
# include <stack>
# include <list>


void reverse_stack(stack<int>&st) {
	list<int> helper;

	while (!st.empty()) {
		helper.push_back(st.top());
		st.pop();
	}

	while (!helper.empty()) {
		st.push(helper.front());
		helper.pop_front();
	}
}



int main() {
	stack<int> s;

	s.push(8);
	s.push(7);
	s.push(6);
	s.push(5);

	// current stack
	stack<int> copy = s;
	while (!copy.empty()) {
		std::cout << copy.top() << std::endl;
		copy.pop();
	}

	std::cout << "-----------------------\n";

	///////////////////////////////////////////////
	reverse_stack(s);
	////////////////////////////////////////

	std::cout << "calling the reverse functin: \n";

	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}