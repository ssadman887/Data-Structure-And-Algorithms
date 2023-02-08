//implementation of circular linked list

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

class cll
{
    public:

    node*head=NULL;

    void push_front(int data)
    {
        node*new_node=new node();

        new_node->data=data;

        if(head==NULL)
        {
            head=new_node;
            head->next=head;
            return;
        }
        node*temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=new_node;
        new_node->next=head;
        head=new_node;
    }

    void push(node *prev_node,int data)
    {
        if(prev_node==NULL)
        {
            push_front(data);
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

        new_node->next=head;

        node*temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=new_node;
    }

    bool search(int x)
    {
        node*i=head;

        while(i->next!=head)
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

       while(i->next!=head)
       {
         if(i->next->data==x)
         {
            break;
         }
         i=i->next;
       }

       if(i->next==head)
       {
        return;
       }
    
       node*temp=i->next;

       i->next=temp->next;

       free(temp);
    }

    void remove_front()
    {
        node*temp=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }

        temp->next=head->next;

        temp=head;
        head=temp->next;
        free(temp);

    }

    void remove_back()
    {
        node*temp=head;

        while(temp->next->next!=head)
        {
            temp=temp->next;
        }

        node*last=temp->next;
        temp->next=head;
        free(last);
    }

    void print()
    {
        node*i=head;

        cout<<i->data;

        i=i->next;

        while(i->next!=head->next)
        {
            cout<<" "<<i->data;
            i=i->next;
        }
        
        cout<<endl;
    }
    
};


int main()
{
    cll a;
    a.push(a.head,5);
    a.push_front(7);
    a.push(a.head,1);
    a.push_front(9);
    a.push_back(8);
    a.push_back(4);
    a.print();
    a.remove_front();
    a.remove_back();
    a.print();

    
}




