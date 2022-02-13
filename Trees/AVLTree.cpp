#include<iostream>

using namespace std;
#define SPACE 10
struct node {
	int data;
	node* left;
	node* right;
};


int height(node* root) {
	if (root == NULL)
	{
		return -1;
	}
	else {
		//getting the height of each subtree
		int lheight = height(root->left);
		int rheight = height(root->right);
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
}

  
int getBalanceFactor(node* n) {
	if (n == NULL)
	{
		return -1;
	}
	else
	{
		return height(n->left) - height(n->right);
	}
}

node* rightRotate(node* root) {
	node* l = root->left;
	node* temp = l->right;
	// Perform rotation  
	l->right = root;
	root->left = temp;
	return l;
}

node* leftRotate(node* root) {
	node* r = root->right;
	node* temp = r->left;
	// Perform rotation  
	r->left = root;
	root->right = temp;
	return r;
}

node* insert(node* root, node* temp) {		//temp is the new node to be inserted
	if (root == NULL) {			//base case
		root = temp;
		return root;
	}
	if (temp->data < root->data) {
		root->left = insert(root->left, temp);
	}
	else if (temp->data > root->data) {
		root->right = insert(root->right, temp);
	}
	else {
		cout << "Error!Duplicate Found!" << endl;
		return root;
	}
	int factor = getBalanceFactor(root);
	// R rotation
	if (factor > 1 && temp->data < root->left->data)
		return rightRotate(root);

	// L rotation  
	if (factor < -1 && temp->data > root->right->data)
		return leftRotate(root);

	// LR rotation  
	if (factor > 1 && temp->data > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// RL rotation  
	if (factor < -1 && temp->data < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

node* mindataNode(node* root) {
	node* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

node* deleteNode(node* root, int data) {
	// base case 
	if (root == NULL) {
		return NULL;
	}
	else if (data < root->data) {
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else { 
		if (root->left == NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		else {
			node* temp = mindataNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}

	int factor = getBalanceFactor(root);
	// Right rotation 
	if (factor == 2 && getBalanceFactor(root->left) >= 0)
		return rightRotate(root);
	// LR rotation 
	else if (factor == 2 && getBalanceFactor(root->left) == -1) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	// L rotation	
	else if (factor == -2 && getBalanceFactor(root->right) <= -0)
		return leftRotate(root);
	//RL rotation 
	else if (factor == -2 && getBalanceFactor(root->right) == 1) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
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



node* search(node* root, int val) {
	if (root == NULL || root->data == val)
		return root;

	else if (val < root->data)
		return search(root->left, val);

	else
		return search(root->right, val);
}

int main() {
	int option, val;
	node* root = NULL;
	do {
		cout << "What operation do you want to perform? " <<
			" Select Option number. Enter 0 to exit." << endl;
		cout << "1. Insert Node" << endl;
		cout << "2. Search Node" << endl;
		cout << "3. Delete Node" << endl;
		cout << "4. Print/Traversal AVL Tree datas" << endl;
		cout << "5. Height of Tree" << endl;
		cout << "6. Clear Screen" << endl;
		cout << "0. Exit Program" << endl;

		cin >> option;
		//Node n1;
		node* new_node = new node();
		switch (option) {
		case 0:
			break;
		case 1:
			cout << "AVL INSERT" << endl;
			cout << "Enter data of TREE NODE to INSERT in AVL Tree: ";
			cin >> val;
			new_node->data = val;
			root = insert(root, new_node);
			cout << endl;
			break;
		case 2:
			cout << "SEARCH" << endl;
			cout << "Enter data of TREE NODE to SEARCH in AVL Tree: ";
			cin >> val;
			//new_node = obj.iterativeSearch(val);
			new_node = search(root, val);
			if (new_node != NULL) {
				cout << "data found" << endl;
			}
			else {
				cout << "data NOT found" << endl;
			}
			break;
		case 3:
			cout << "DELETE" << endl;
			cout << "Enter data of TREE NODE to DELETE in AVL: ";
			cin >> val;
			new_node = search(root, val);
			if (new_node != NULL) {
				root = deleteNode(root, val);
				cout << "data Deleted" << endl;
			}
			else {
				cout << "data NOT found" << endl;
			}
			break;
		case 4:
			cout << "PRINT 2D: " << endl;
			//cout <<"Print Level Order BFS: \n";
			//obj.printLevelOrderBFS(obj.root);
			//cout <<endl;
			//	      cout <<"PRE-ORDER: ";
			//	      obj.printPreorder(obj.root);
			//	      cout<<endl;
			//	      cout <<"IN-ORDER: ";
			//	      obj.printInorder(obj.root);
			//	      cout<<endl;
			//	      cout <<"POST-ORDER: ";
			//	      obj.printPostorder(obj.root);
			break;
		case 5:
			cout << "TREE HEIGHT" << endl;
			cout << "Height : " << height(root) << endl;
			break;
		case 6:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
}