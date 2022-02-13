#include<iostream>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};
int countNodes = 0;
int index = 0;
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
node* rightRotate(node* x)
{
	node* y = x->left;
	node* temp = y->right;
	//node* z = y->left;
	y->right = x;
	x->left = temp;
	return y;
}
node* leftRotate(node* x)
{
	node* y = x->right;
	node* temp = y->left;
	y->left = x;
	x->right = temp;
	return y;
}
node* createNode(node* root, int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	//root = temp;
	return temp;
}
int calculateBF(node* root)
{
	return getHeight(root->left) - getHeight(root->right);
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
	int bf = calculateBF(root);
	if (bf > 1 && data < root->left->data)
	{
		return rightRotate(root);
	}
	else if (bf > 1 && data > root->left->data)	//zig-zag path
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	else if (bf < -1 && data > root->right->data)
	{
		return leftRotate(root);
	}
	else if (bf < -1 && data < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	else
	{
		return root;	//unchanged root
	}
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
	int bf = calculateBF(root);
	if (bf > 1 && calculateBF(root->left) >= 0)
	{
		return rightRotate(root);
	}
	// Left Right Case 
	else if (bf > 1 && calculateBF(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// Right Right Case 
	else if (bf < -1 && calculateBF(root->right) <= 0)
	{
		return leftRotate(root);
	}
	// Right Left Case 
	else if (bf < -1 && calculateBF(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	else
	{
		return root;
	}
}
int getTotalNodes(node* root)
{
	if (root == NULL)
		return countNodes;
	countNodes++;
	getTotalNodes(root->left);
	getTotalNodes(root->right);
}
void modifiedInOrder(node* root, int* elements)
{
	if (root == NULL)
		return;
	modifiedInOrder(root->left, elements);
	elements[index] = root->data;
	index++;
	modifiedInOrder(root->right, elements);
}
void searchPair(node* root, int sum)
{
	int total = getTotalNodes(root);
	int* elements = new int[total];
	modifiedInOrder(root, elements);
	int left = 0;
	int right = total - 1;
	/*for (int i = 0; i < total; i++)
	{
		cout << elements[i] << " ";
	}*/
	cout << endl;
	while (left < right)
	{
		if (elements[left] + elements[right] > sum)
			right--;
		else if (elements[left] + elements[right] < sum)
			left++;
		else
		{
			cout << elements[left] << " " << elements[right] << endl;
			return;
		}
	}
	cout << "Sum not found!" << endl;
}
int main()
{
	node* root = NULL;
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 5);
	root = insert(root, 2);
	root = insert(root, 16);
	root = insert(root, 9);
	root = insert(root, 3);
	//preOrder(root);
	//cout << endl;
	searchPair(root, 14);
}