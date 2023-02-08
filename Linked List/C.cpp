#include <iostream>
#include <unordered_set>

struct Node {
  int data;
  Node* next;
};

void removeDuplicates(Node* head) {
  if (!head) return;

  std::unordered_set<int> set;
  set.insert(head->data);

  Node* prev = head;
  Node* current = head->next;
  while (current) {
    if (set.count(current->data)) {
      prev->next = current->next;
      delete current;
    } else {
      set.insert(current->data);
      prev = current;
    }
    current = prev->next;
  }
}

int main() {
  // create a linked list here

  removeDuplicates(head);

  // display the linked list here

  return 0;
}
