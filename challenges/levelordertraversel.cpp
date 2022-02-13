#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/

    void levelOrder(Node * root) {
        queue<Node*> nodes;
        Node* current = NULL;
        nodes.push(root);
        while (nodes.size() != 0)
        {
            current = nodes.front();
            cout << current->data << " ";
            if (current->left != NULL)
            {
                nodes.push(current->left);
            }
            if (current->right != NULL)
            {
                nodes.push(current->right);
            }
            nodes.pop();
        }
        cout << endl;
    }

}; //End of Solution