#include<iostream>

using namespace std;

struct node
{
	node* prev;
	int data;
	node* next;
};

void printList(node* tail)
{
	node* head = tail->next;
	do
	{
		cout << head->data << endl;
		head = head->next;
	} while (head != tail->next);
}

node* addToList(node* tail, int data)
{
	node* temp = new node;
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	tail = temp;
	return tail;
}
node* addAtBeginning(node* tail, int data)
{
	node* temp = new node;
	node* head = tail->next;
	tail->next = temp;
	temp->prev = tail;
	temp->next = head;
	head->prev = temp;
	temp->data = data;
	return tail;
}
node* addAtEnd(node* tail, int data)
{
	node* head = tail->next;
	node* temp = new node;
	temp->prev = tail;	//pointing prev part of new node to previously ending node
	tail->next = temp;	//pointing previosuly ending node to new node
	temp->next = head;	//pointing next part of new node to tail
	head->prev = temp;	//pointing prev part of head to tail
	temp->data = data;
	return temp;	//returning tail
}
node* addAtPos(node* tail, int data, int pos)
{
	if (pos == 1)
	{
		tail = addAtBeginning(tail, data);
		return tail;
	}
	int count = 1;
	node* temp = new node;
	node* before = tail->next;
	node* after = tail->next;
	while (count < pos)
	{
		before = after;
		after = after->next;
		count++;
	}
	if (after == tail->next)
	{
		tail = addAtEnd(tail, data);
		return tail;
	}
	before->next = temp;
	temp->prev = before;
	temp->data = data;
	temp->next = after;
	after->prev = temp;
	return tail;
}
node* deleteAtBeginning(node* tail)
{
	node* head = tail->next;
	node* temp = head;
	head = head->next;	//making 2nd node head
	head->prev = tail;		//linking head with tail
	tail->next = head;	//same
	delete temp;	//deleting first node
	temp = NULL;
	return tail;
}
node* deleteAtEnd(node* tail)
{
	node* head = tail->next;
	node* temp = tail;
	tail = tail->prev;	//making 2nd last node tail 
	tail->next = head;
	head->prev = tail;
	delete temp;
	temp = NULL;
	return tail;
}
node* deleteAtPos(node* tail, int pos)
{
	int count = 1;
	node* head = tail->next;
	node* before = head;
	node* posNode = head;
	while (count < pos - 1)
	{
		before = before->next;	//node at pos - 1
		count++;
	}
	posNode = before->next;	//node at pos
	before->next = posNode->next;		//node at pos - 1 to pos + 1
	if (posNode->next != tail->next)
	{
		posNode->next->prev = before;		//node at pos + 1 to previous
	}
	else
	{
		//tail = deleteAtEnd(tail);
		//return tail;
		tail = before;
		tail->next = head;
		head->prev = tail;
	}
	delete posNode;	//deleting pos node
	posNode = NULL;
	return tail;
}
int main()
{
	node* tail = new node;
	tail = addToList(tail, 10);		//creates the list
	tail = addAtBeginning(tail, 20);
	tail = addAtBeginning(tail, 40);
	tail = addAtEnd(tail, 50);
	tail = addAtPos(tail, 30, 5);
	//tail = deleteAtBeginning(tail);
	//tail = deleteAtEnd(tail);
    tail = deleteAtPos(tail, 5);
	printList(tail);
}