#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
void printList(node* n)
{
	if (n == NULL)
	{
		cout << "Linked list is empty" << endl;
		return;
	}
	while (n != NULL)
	{
		cout << n->data << endl;
		n = n->next;
	}
}
node* addAtBeginning(node* head, int data)
{
	if (head == NULL)
	{
		cout << "LL is empty" << endl;
		return head;
	}
	node* temp = new node;
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}

node* addAtEnd(node* head, int data)
{
	if (head == NULL)
	{
		cout << "LL is empty" << endl;
		return head;
	}
	node* n = new node;	//node to be attatched at end
	node* temp = head;	//temprory pointer
	//traversing till the end of list
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//assigning data
	n->data = data;
	temp->next = n;
	n->next = NULL;
	return head;
}
node* addAtPos(node* head, int data, int pos)
{
	int count = 1;
	node* temp = head;
	node* temp2 = head;
	node* n = new node;
    if (position == 1)
    {
        head = insertAtStart(head, data);
        return head;
    }
	//traversing to pos - 1 node
	while (count < pos)
	{
		temp = temp2;	//storing the node before pos
		temp2 = temp2->next;	//storing the node after pos
		count++;
	}
	//pointing node to n
	temp->next = n;
	//pointing n to node 2
	n->next = temp2;
	n->data = data;
	return head;
}
node* deleteAtBeginning(node* head)
{
	node* temp = NULL;
	temp = head;
	head = head->next;
	delete temp;
	temp = NULL;
	return head;
}
node* deleteAtEnd(node* head)
{
	node* temp = NULL;
	node* temp2 = NULL;
	temp = head;
	//traversing till final node
	while (temp->next != NULL)
	{
		temp2 = temp;	//storing 2nd last node
		temp = temp->next;	//storing final node
	}
	delete temp;	//deleting final node
	temp = NULL; //clearing after deletion
	temp2->next = NULL;		//pointing 2nd last node to null
	return head;
}
node* deleteAtPos(node* head, int pos)
{
	if (pos == 1)
	{
		head = deleteAtBeginning(head);
		return head;
	}
	int count = 1;
	node* temp = head;
	node* temp2 = head;
	while (count < pos)
	{
		temp = temp2;	//node at pos - 1
		temp2 = temp2->next;	//node at pos
		count++;
	}
	temp->next = temp2->next;	//pointing node at pos-1 to pos+1
	delete temp2;	//deleting pos node
	temp2 = NULL;
	return head;
}
node* reverseList(node* head)
{
	node* temp = NULL;
	node* temp2 = NULL;
	while (head != NULL)
	{
		temp = head->next;
		head->next = temp2;
		temp2 = head;
		head = temp;
	}
	head = temp2;
	return head;
}
node* deleteList(node* head)
{
	node* temp = head;
	while (temp != NULL)
	{
		head = temp;
		temp = temp->next;
		delete head;
		head = NULL;
	}
	return head;
}
int main()
{
	node* head = NULL;
	head = new node;
	head->data = 30;
	head->next = NULL;
	head = addAtBeginning(head, 20);
	head = addAtBeginning(head, 10);
	head = addAtEnd(head, 40);
	head = addAtPos(head, 50, 3);
	//head = deleteAtPos(head, 2);
	//head = deleteAtBeginning(head);
	//head = deleteAtEnd(head);
	//head = deleteList(head);
	//head = reverseList(head);
	printList(head);
	return 0;
}