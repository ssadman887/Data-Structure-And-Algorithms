// Implementation of Stack using linked list and pointer
#include <iostream>
using namespace std;

class node{

public:
	int val;
	node* prev;

	node(){
		val = 0;
		prev = NULL;
	}
};

class stack{

private:

	node* end;

public:
	stack(){
		end = NULL;
	}

	void print();

	void pop();

	void push(int a);

	int peek(void);

	bool search(int a);
};

//adds to end of stack
void stack::push(int a){
	node* temp = new node();

	temp->val = a;
	temp->prev = end;

	end = temp;
}

//returns last element of stack
int stack::peek(void){

	return end->val;
}

//removes last element of stack
void stack::pop(void){

	if(end == NULL){
		return;
	}

	node* temp = end;
	end = end->prev;
	free(temp);
}

//prints the stack back to front
void stack::print(void){
	node* temp = end;

	while(temp != NULL){
		cout << temp->val << " ";
		temp = temp->prev;
	}
	cout << endl;
}

bool stack::search(int a){
	
	node* temp = end;

	while(temp != NULL){
		if(temp->val == a){
			return true;
		}
		temp = temp->prev;
	}

	return false;
}

int main(void){

	stack mystack;

	mystack.push(5);
	mystack.push(5);
	mystack.push(45);
	mystack.push(7);
	mystack.push(15);

	mystack.print();

	cout << mystack.search(10);

	return 0;
}
