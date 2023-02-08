//implementation of singly linked list

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node*next;

    node()
    {
        next=NULL; 
    }
};

class sll
{
    public:

    node*head=NULL;

    void push_front(int data)
    {
        node *new_node=new node();
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }

    void push(node *prev_node,int data)
    {
        if(prev_node==NULL)
        {
            cout<<"error: previous node can't be NULL"<<endl;
            return;
        }

        node*new_node=new node();

        new_node->data=data;
        new_node->next=prev_node->next;
        prev_node->next=new_node;
    }

    void push_back(int data)
    {
        node*new_node=new node();

        new_node->data=data;

        node*last=head;

        if(last==NULL)
        {
            head=new_node;
            return;
        }

        while(last->next!=NULL)
        {
            last=last->next;
        }

        last->next=new_node;
    }

    bool search(int x)
    {
        node*i=head;

        while(i!=NULL)
        {
           if(i->data==x)
           {
             return true;
           }
           i=i->next;
        }

        return false;
        
    }

    void remove(int x)
    {
       node*i=head;

       if(i->data==x)
       {
         head=i->next;
         free(i);
         return;
       }

       while(i->next!=NULL)
       {
          if(i->next->data==x)
          {
            break;
          }
          i=i->next;
       }

       if(i->next==NULL)
       {
        return;
       }
    
       node*temp=i->next;

       i->next=temp->next;

       free(temp);
    }

    void print()
    {
        node*i=head;

        while(i!=NULL)
        {
            cout<<i->data<<" ";
            i=i->next;
        }
        cout<<endl;
    }
    
};

int main()
{
    sll a;
    a.push_front(5);
    a.push_front(7);
    a.push(a.head->next,1);
    a.push_front(9);
    a.push_back(8);
    a.push_back(4);

    a.print();

    a.remove(9);

    a.print();
}






