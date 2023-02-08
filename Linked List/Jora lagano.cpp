#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    Node dummy;
    Node* tail = &dummy;
    dummy.next = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = (head1 != nullptr) ? head1 : head2;

    return dummy.next;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* tail1 = nullptr;
    Node* tail2 = nullptr;

    // Initialize linked list 1
    Node n1, n2, n3;
    n1.data = 1;
    n1.next = &n2;
    n2.data = 3;
    n2.next = &n3;
    n3.data = 5;
    n3.next = nullptr;
    head1 = &n1;
    tail1 = &n3;

    // Initialize linked list 2
    Node m1, m2, m3;
    m1.data = 2;
    m1.next = &m2;
    m2.data = 4;
    m2.next = &m3;
    m3.data = 6;
    m3.next = nullptr;
    head2 = &m1;
    tail2 = &m3;

    // Call the mergeLists function
    Node* head = mergeLists(head1, head2);

    // Print the merged linked list
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
