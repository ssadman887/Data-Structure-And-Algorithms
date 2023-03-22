// C++ program to print
// right view of a BST
#include <bits/stdc++.h>
using namespace std;

// Given Node node
struct node {
	int key;
	struct node *left, *right;
};

// Function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(
			sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to insert a new node with
// given key in BST
struct node* insert(struct node* node, int key)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return newNode(key);

	// Otherwise, recur down the tree
	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}

	// Return the node pointer
	return node;
}

// Function to print the right view
// of a binary tree.
void rightViewUtil(struct node* root,
				int level,
				int* max_level)
{
	// Base Case
	if (root == NULL)
		return;

	// If this is the last Node of its level
	if (*max_level < level) {
		cout <<"\t"<< root->key;
		*max_level = level;
	}

	// Recur for right subtree first,
	// then left subtree
	rightViewUtil(root->right, level + 1,
				max_level);

	rightViewUtil(root->left, level + 1,
				max_level);
}

// Wrapper over rightViewUtil()
void rightView(struct node* root)
{
	int max_level = 0;
	rightViewUtil(root, 1, &max_level);
}

// Driver Code
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80
*/
	struct node* root = NULL;

	// Creating the BST
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// Function Call
	rightView(root);

	return 0;
}


