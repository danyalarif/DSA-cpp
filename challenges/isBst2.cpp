/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

int getMax(Node* root)
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
int getMin(Node* root)
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
    bool checkBST(Node* root) {
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