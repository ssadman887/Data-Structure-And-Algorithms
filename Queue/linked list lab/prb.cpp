#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node {
public:
    int data;
    Node* next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int, inserts
// a new node on the front of the list.
void push(Node** head_ref, int new_data) {

    // 1. allocate node
    Node* new_node = new Node();

    // 2. put in the data
    new_node->data = new_data;

    // 3. Make next of new node as head
    new_node->next = (*head_ref);

    // 4. move the head to point
    // to the new node
    (*head_ref) = new_node;
}

// Merge two sorted linked lists
Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->data <= l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

// Merge all linked lists in the given array using divide and conquer strategy
Node* mergeKLists(vector<Node*>& lists, int left, int right) {
    if (left == right) return lists[left];
    if (left + 1 == right) return mergeLists(lists[left], lists[right]);
    int mid = (left + right) / 2;
    Node* l1 = mergeKLists(lists, left, mid);
    Node* l2 = mergeKLists(lists, mid+1, right);
    return mergeLists(l1, l2);
}

// This function prints contents of
// linked list starting from head
void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

// Driver code
int main() {

    // Start with empty list
    vector<Node*> lists;

    // Linked list 1
    Node* head1 = nullptr;
    push(&head1, 5);
    push(&head1, 4);
    push(&head1, 1);
    lists.push_back(head1);

    // Linked list 2
    Node* head2 = nullptr;
    push(&head2, 4);
    push(&head2, 3);
    push(&head2, 1);
    lists.push_back(head2);

    // Linked list 3
    Node* head3 = nullptr;
    push(&head3, 6);
    push(&head3, 2);
    lists.push_back(head3);

    // Merge all linked lists using divide and conquer strategy
    Node* merged = mergeKLists(lists, 0, lists.size()-1);

    cout << "Merged Linked list is:";
    printList(merged);

    return 0;
}
