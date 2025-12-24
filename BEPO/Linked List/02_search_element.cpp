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

// iterative search
bool iterativeSearch(ListNode* &head, int key) {
	ListNode* temp = head;
	while (temp) {
		if (temp->val == key) return true;
		temp = temp->next;
	}
	return false;
}

// recursive search
bool recursiveSearch(ListNode* head, int key) {

	if (head == nullptr) {
		return false;
	}

	if (head->val == key) return true;

	return recursiveSearch(head->next, key);
}

int main() {
	ListNode* head = nullptr;
	int a{};
	while (cin >> a) {
		InsertAtHead(head, a);
	}

	Print(head);

	cout << iterativeSearch(head, 50) << "\n";
	cout << recursiveSearch(head, 100) << "\n";

	return 0;
}