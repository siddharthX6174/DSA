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

ListNode* middle(ListNode* &head) {
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr and fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


int main() {
	ListNode* head = nullptr;

	int x{};
	while (cin >> x) {
		InsertAtHead(head, x);
	}

	// find middle
	ListNode* mid = middle(head);

	ListNode* head2 = mid->next;

	// break
	mid -> next = nullptr;

	// reverse 2nd one
	reverseList(head2);

	// make 2 new pointers on each ll to iterate and connect them..
	ListNode* h1 = head;
	ListNode* h2 = head2;
	ListNode* temp1 = nullptr;
	ListNode* temp2 = nullptr;

	while (h2 != nullptr) {
		temp1 = h1->next;
		temp2 = h2->next;

		h1->next = h2;
		h2->next = temp1;
		h1 = temp1;
		h2 = temp2;
	}

	Print(head);

}