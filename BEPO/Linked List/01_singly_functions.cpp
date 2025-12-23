#include <iostream>
using namespace std;

template <typename T>
class node {
public:
	T data;
	node<T>* next;

	node() {
		next = nullptr;
	}

	node(T x) {
		data = x;
		next = nullptr;
	}
};

// insert at head function
template <typename T>
void InsertAtHead(node<T>* &head, T x) {
	if (head == nullptr) {
		node<T>* temp = new node (x);
		head = temp;
	} else {
		node<T>* temp = new node (x);
		temp->next = head;
		head = temp;
	}
}

// iteration on linked list
template <typename T>
void Print(node<T>* head) {
	node<T>* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

// find the length
template<typename T>
int length(node<T>* &head) {
	int l{};
	node<T>* temp = head;
	while (temp != nullptr) {
		l++;
		temp = temp->next;
	}
	return l;
}

int main() {
	node<int>* head = nullptr;
	int x;

	while (cin >> x) {
		InsertAtHead(head, x);
	}

	Print(head);

	cout << length(head) << '\n';


}
