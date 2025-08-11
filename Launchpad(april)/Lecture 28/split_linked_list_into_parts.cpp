# include <iostream>
# include <std::vector>

class node {
public:
	int data;
	node* next;

	// self constructor
	node() {
	}

	//constructor
	node(int inputdata) {
		data = inputdata;
		next = nullptr;
	}
};

// insertion in sinlgy linked list
void InsertAtHead(node* &head, int x) {
	if (head == nullptr) {
		node* temp = new node(x);
		head = temp;
	} else {
		node* temp = new node(x);
		temp->next = head;
		head = temp;
	}
}

int Length(node* head) {
	int l{};
	while (head) {
		l++;
		head = head->next;
	}
	return l;
}

int main() {
	node* head = nullptr;
	int x{};
	while (std::cin >> x) {
		InsertAtHead(head, x);
	}

	std::vector<node*> ans;


	int n = Length(head);
	int me = n / k;
	int ee = n % k;

	int count = 1 ; // k parts maei se maine itne parts bna diye hai
	// maine 1 se is liye initialise kiya hai kuki akhiri part nhi banana


	if (me == 0) {
		// k>n
		// every part can have only 1 element at max
		// i want to break ll after 1 node

		for (int i = 0; i < k; i++) {
			if (head != nullptr) {
				ListNode* n = head->next;

				// break your ll
				head->next = nullptr;
				ans.push_back(head);
				head = n;

			} else {
				ans.push_back(NULL);
			}
		}
	} else {
		// k<=n

		ans.push_back(head);

		// Now i have to break the ll according to ME + 1/0 for EE

		int x = (ee > 0) ? 1 : 0;
		ee--;

		for (int i = 0; i < me + x; i++) {
			head = head->next;
		}

		// now my head is at breakage point
		node* n = head->next;
		head->next = nullptr;
		head = n;

		count ++;
		if (count == k) {
			// you are at the last part;
			ans.push_back(head);
			break;
		}
	}

	return ans;

}