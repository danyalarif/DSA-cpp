//Is This a Binary Search Tree?


/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

Node* queue[10000];
int queueSize = sizeof(queue) / sizeof(queue[0]);
int front = -1;
int rear = -1;
void enqueue(Node* ptr)
{
    if (rear == queueSize - 1)
    {
        cout << "Queue Overflow!\n" << endl;
        return;
    }
    if (front == -1)
        front++;
    rear++;
    queue[rear] = ptr;
}
Node* getfront()
{
    return queue[front];
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow!\n" << endl;
        return;
    }
    front++;
}
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
        Node* current = NULL;
        enqueue(root);
        while (front <= rear)
        {
            current = getfront();
            if (current->left != NULL && getMax(current->left) > current->data)
            {
                return false;
            }
            else if (current->left != NULL && getMax(current->left) == current->data)
            {
                return false;
            }
            if (current->right != NULL && getMin(current->right) < current->data)
            {
                return false;
            }
            else if (current->right != NULL && getMin(current->right) == current->data)
            {
                return false;
            }
            if (current->left != NULL)
            {
                enqueue(current->left);
            }
            if (current->right != NULL)
            {
                enqueue(current->right);
            }
            dequeue();
            //cout << front << endl;
        }
        return true;
	}