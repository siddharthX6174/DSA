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

void cycleCreation(ListNode* &head) {
	ListNode* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = head->next->next;
}

// detection of cycle :->  2 person running with differnt sppeeds in a circular loop meet at a point
bool isCycle(ListNode* &head) {
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != nullptr and fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) return true;
	}

	return false;
}

int main() {
	ListNode* head = nullptr;
	int a{};
	while (cin >> a) {
		InsertAtHead(head, a);
	}


	cycleCreation(head);
	cout << isCycle(head);

}