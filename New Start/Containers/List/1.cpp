# include <iostream>
# include <list>
using namespace std;


// display the list function
void display (list<int> &lst) {
	for (list<int>::iterator it = lst.begin(); it != prev(lst.end()); it++) {
		cout << *it << " -> ";
	}
	cout << *lst.end();
	cout << endl;
}

int main() {
	// forming the list
	list<int> lst1; // list of size 0
	list<int> lst2(8); // list of size 8

	int size{};
	cin >> size;
	int x{};
	for (int i = 0; i < size; i++) {
		cin >> x;
		lst1.push_back(x);
	}

	display(lst1);

	return 0;
}