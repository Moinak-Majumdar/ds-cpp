#include<iostream>
#include<stdlib.h>
#define COUNT 5

using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};
struct node *root;

// Function to create a new node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* Function to find the minimum value node */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

/* Function to delete the given node */
struct node* delete_node(struct node* root, int data)
{
	if (root == NULL)
		return root;
	if (data < root->data)
		root->left = delete_node(root->left, data);	
	else if (data > root->data)
		root->right = delete_node(root->right, data);
	else
	{

		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		
		struct node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

// Function to do inorder traversal 
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<" "<<root->data;
		inorder(root->right);
	}
}

/* Function to insert a new node */
struct node* insert(struct node* node, int data)
{

	if (node == NULL)
	return newNode(data);

	if (data < node->data)
	node->left = insert(node->left, data);
	else if (data > node->data)
	node->right = insert(node->right, data);
	return node;
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
	root = NULL;
	cout<<"\nEnter the number of nodes : ";
	cin>>n;
	int i;
	int data;
	cout<<"\nInput the nodes of the binary search tree : ";
	if(n > 0)
		{
		cin>>data;
		root = insert(root, data);
		}
	for(i = 1; i < n; i++)
		{
		cin>>data;
		insert(root, data);
		}
	cout<<"\nInorder traversal of the BST : ";
	inorder(root);
	cout<<endl;
	print(root,4);
	cout<<endl;
	
	int del_ele;
	cout<<"\nEnter the node to be deleted : ";
	cin>>del_ele;
	delete_node(root, del_ele);	
	cout<<"\nInorder traversal after deletion : ";
	inorder(root);
	cout<<endl;
	print(root,4);
	cout<<endl;

	return 0;
}
