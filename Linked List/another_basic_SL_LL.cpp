#include <bits/stdc++.h>
 
struct node{
    int data;
    struct Node *next;
};

struct Node *head;
 void insert(int x){
    struct Node *temp = (Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp -> next = NULL;
    head = temp;
 }




int main(){
    head = NULL;
    int t;
    printf("Enter number of elements");
    scanf("%d",&t);
    for (int i = 0; i < t; i++)
    {

        int x;
        scanf("%d",&x);
        insert(x);
        print(x);
    }
    

    return 0;
}