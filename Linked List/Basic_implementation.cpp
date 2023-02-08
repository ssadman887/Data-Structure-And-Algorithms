#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node *next;


};

class linkedlist{
    private:
    Node *head;

    public:
        linkedlist(){
            head = NULL;
        }

        void insert(int data){
            Node *temp = new Node;
            temp->data= data;
            temp->next=head;
            head=temp;

        }

        void display(){
            Node *temp= head;
            while(temp!= NULL){
                std::cout << temp->data << "";
                temp= temp->next;
            }

        }
};



int main() {

	linkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    
	return 0;
}


