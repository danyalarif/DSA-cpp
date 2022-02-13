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
	//root = temp;
	return temp;
}
node* insert(node* root, int data)
{
	if (root == NULL)
	{
		root = createNode(root, data);

	}
	else if (data < root->data)		//going to left if number is smaller 
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	return root;	//this will execute for each function call;so last call will be the top root which will be returned
}
bool search(node* root, int data)
{
	if (root == NULL)
		return false;
	else if (data < root->data)
		search(root->left, data);
	else if (data > root->data)
		search(root->right, data);
	else
		return true;
}
void preOrder(node* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(node* root)
{
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}
void inOrder(node* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);

}
node* minNode(node* root)
{
	node* temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}
node* deleteNode(node* root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (data < root->data)
	{
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = deleteNode(root->right, data);
	}
	else
	{
		node* temp = NULL;
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			return root;
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			delete root;
			return temp;
		}
		//if two children
		temp = minNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int getHeight(node* root)
{

	if (root == NULL)
	{
		return -1;
	}
	//getting the height of each subtree
	int lheight = getHeight(root->left);
	int rheight = getHeight(root->right);
	//returning the larger height
	if (lheight > rheight)
	{
		return (lheight + 1);
	}
	else
	{
		return (rheight + 1);
	}
}
int getMax(node* root)
{
	int max = root->data;
	while (root != NULL)
	{
		if (root->data > max)
		{
			max = root->data;
		}
		root = root->right;
	}
	return max;
}
int getMin(node* root)
{
	int min = root->data;
	while (root != NULL)
	{
		if (root->data < min)
		{
			min = root->data;
		}
		root = root->left;
	}
	return min;
}
bool checkBST(node* root) {
	if (root == NULL)
	{
		return true;
	}
	if (root->left != NULL && getMax(root->left) > root->data)
	{
		return false;
	}
	else if (root->left != NULL && getMax(root->left) == root->data)
	{
		return false;
	}
	if (root->right != NULL && getMin(root->right) < root->data)
	{
		return false;
	}
	else if (root->right != NULL && getMin(root->right) == root->data)
	{
		return false;
	}
	if (!(checkBST(root->left)))
		return false;
	if (!(checkBST(root->right)))
		return false;
	return true;
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