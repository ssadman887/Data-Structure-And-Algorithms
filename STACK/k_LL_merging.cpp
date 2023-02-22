#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MergeKSortedList {
public:
    ListNode* mergeKLists(ListNode** lists, int k) {
        // Base condition
        if (k == 0) {
            return nullptr;
        }
        // Merge lists in pairs
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = merge(lists[i], lists[k - 1 - i]);
            }
            k = (k + 1) / 2;
        }
        return lists[0];
    }

private:
    ListNode* merge(ListNode* left, ListNode* right) {
        // Dummy node
        ListNode* head = new ListNode(-1);
        // Temp node
        ListNode* temp = head;
        // Loop until any of the lists becomes null
        while (left != nullptr && right != nullptr) {
            // Choose the smaller value from left and right lists
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        // Take all nodes from left list if remaining
        while (left != nullptr) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        // Take all nodes from right list if remaining
        while (right != nullptr) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
        return head->next;
    }
};
