#include<iostream>
using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;

	ListNode() {
		next = nullptr;
	}

	ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

void InsertAtHead(ListNode* &head, int x) {
	if (head == nullptr) {
		ListNode* temp = new ListNode (x);
		head = temp;
	} else {
		ListNode* temp = new ListNode (x);
		temp->next = head;
		head = temp;
	}
}

void Print(ListNode* &head) {
	ListNode* temp = head;
	while (temp) {
		cout << temp->val << " --> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

void reverseList(ListNode* &head) {
	ListNode* prev = nullptr;
	ListNode* current = head;
	ListNode* temp = head;

	while (current != nullptr) {
		temp = current->next;
		// task
		current -> next = prev;

		// increment the index
		prev = current;
		current = temp;
	}

	head = prev;
}

int main() {
	ListNode* head = nullptr;
	int a{};
	while (cin >> a) {
		InsertAtHead(head, a);
	}

	Print(head);

	cout << "reversing it \n";

	reverseList(head);

	Print(head);
}