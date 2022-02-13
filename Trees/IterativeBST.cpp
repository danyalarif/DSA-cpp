//Implementation of iterative BST
#include<iostream>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};
node* createNode(node* root, int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
node* deleteNode(node* root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	node* temp = root;
	node* prev = NULL;
	while (temp != NULL && temp->data != data)
	{
		prev = temp;
		if (data < temp->data)
		{
			temp = temp->left;
		}
		else if (data > temp->data)
		{
			temp = temp->right;
		}
		else
		{
			break;
		}
	}
	if (temp->left == NULL && temp->right == NULL)		//no children
	{
		if (prev->left == temp)		//if temp is left child of previous
		{
			prev->left = NULL;
		}
		else if (prev->right == temp)
		{
			prev->right = NULL;
		}
		delete temp;
		temp = NULL;
	}
	else if (temp->right == NULL)		//left child only
	{
		if (prev->left == temp)
		{
			prev->left = temp->left;
		}
		else if (prev->right == temp)
		{
			prev->right = temp->left;
		}
	}
	else if (temp->right == NULL)		//right child only
	{
		if (prev->left == temp)
		{
			prev->left = temp->right;
		}
		else if (prev->right == temp)
		{
			prev->right = temp->right;
		}
	}
	//two children
	else
	{
		//node* min = minNode(temp->right);
		//node* min = NULL;
		node* prev2 = NULL;
		node* temp2 = temp->right;
		while (temp2->left != NULL)
		{
			prev2 = temp2;
			temp2 = temp2->left;
		}
		temp->data = temp2->data;
		if (temp2->right != NULL)		//if temp2 has a right child
		{
			prev2->left = temp2->right;
		}
		else
		{
			prev2->left = NULL;
		}
	}
	return root;
}
node* insert(node* root, int data)
{
	if (root == NULL)
	{
		root = createNode(root, data);
		return root;
	}
	node* temp = root;
	node* prev = NULL;
	while (temp != NULL)
	{
		prev = temp;
		if (data < temp->data)
		{
			temp = temp->left;
		}
		else if (data > temp->data)
		{
			temp = temp->right;
		}
	}
	if (data < prev->data)
	{
		prev->left = createNode(root, data);
	}
	else
	{
		prev->right = createNode(root, data);
	}
	return root;
}
bool search(node* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	node* temp = root;
	while (temp != NULL)
	{
		if (data < temp->data)
		{
			temp = temp->left;
		}
		else if (data > temp->data)
		{
			temp = temp->right;
		}
		else
		{
			return true;
		}
	}
	return false;
}
void preOrder(node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
int main()
{
	node* root = NULL;
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 12);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 45);
	root = insert(root, 55);
	preOrder(root);
	cout << endl;
	root = deleteNode(root, 50);
	preOrder(root);
}