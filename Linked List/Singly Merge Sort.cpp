#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head, int data)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void split(struct node *head, struct node **a, struct node **b)
{
    struct node *fast, *slow;
    slow = head;
    fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    (*a) = head;
    (*b) = slow->next;
    slow->next = NULL;
}

struct node *merge(struct node *a, struct node *b)
{
    struct node *result = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    if (a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

void mergeSort(struct node **head)
{
    struct node *a, *b;
    if ((*head == NULL) || ((*head)->next == NULL))
        return;
    split(*head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    (*head) = merge(a, b);
}

void printList(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);
    printf("Linked List before sorting \n");
    printList(head);
    mergeSort(&head);
    printf("Linked List after sorting \n");
    printList(head);
    return 0;
}
