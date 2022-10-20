#include <stdlib.h>
#include <iostream>

using namespace std;
#define COUNT 5

/* A binary tree node has data,pointer to left child and a pointer to right child */
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// New node creation.
struct node *newNode(int data) 
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));

  temp->data = data;

  temp->left = NULL;
  temp->right = NULL;
  return (temp);
}

/* Function to insert a new node with given key in BST */
struct node* insert(struct node* node, int data)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
	return newNode(data);
	/* Recur down the tree */
	if (data < node->data)
	node->left = insert(node->left, data);
	else if (data > node->data)
	node->right = insert(node->right, data);
	return node;
}

// Traverse Preorder
void traversePreOrder(struct node *temp) 
{
  if (temp != NULL) {
    cout << " " << temp->data;
    traversePreOrder(temp->left);
    traversePreOrder(temp->right);
  }
}

// Traverse Inorder
void traverseInOrder(struct node *temp) 
{
  if (temp != NULL) {
    traverseInOrder(temp->left);
    cout << " " << temp->data;
    traverseInOrder(temp->right);
  }
}


void print(node *root, int space)  
{  
   
    if(root==NULL)  
        return;  
  
    space += COUNT;  

    print(root->right,space);  
    cout<<"\n"; 
	 
    for (int i=COUNT;i<space;i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  

    print(root->left,space);  
}  
  
int main() 
{
  	int n;
	struct node *root = NULL;
	cout<<"\nEnter the number of nodes : ";
	cin>>n;
	int i;
	int data;
	cout<<"\nInput the nodes of the binary search tree : ";
	if(n > 0)
		{
		cin>>data;
		root = insert(root,data);
		}
	for(i=1;i< n;i++)
		{
		cin>>data;
		insert(root,data);
		}
  
  cout<<"\t\nTREE :\n\n";
  print(root,4);

  cout<<"\n\tpreorder traversal: ";
  traversePreOrder(root);
  cout<<"\n\n\tInorder traversal: ";
  traverseInOrder(root);
}
