class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* final = nullptr;
        ListNode* h1 = list1;
        ListNode* h2 = list2;

        // choose head (same as yours)
        if (h1->val <= h2->val) {
            final = h1;
            h1 = h1->next;
        } else {
            final = h2;
            h2 = h2->next;
        }
        ListNode* tail = final;

        while (h1 != nullptr && h2 != nullptr) {
            if (h1->val <= h2->val) {
                tail->next = h1;
                h1 = h1->next;
            } else {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }

        // attach remaining safely
        if (h1 != nullptr) {
            tail->next = h1;
        } else {
            tail->next = h2;
        }

        return final;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (h1 == nullptr) return h2;
        if (h2 == nullptr) return h1;

        if (h1->val <= h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        }
        if (h2->val <= h1->val) {
            h2->next = mergeTwoLists(h1, h2->next);
            return h2;
        }

        return nullptr;
    }
};