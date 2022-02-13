#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
void printList(node* tail)
{
	node* head = tail->next;	//getting head
	do
	{
		cout << head->data << endl;
		head = head->next;
	}	while (head != tail->next);		//printing until head reaches back to head	full round complete
}
node* addtoEmpty(int data)
{
	node* temp = new node;
	temp->data = data;	
	temp->next = temp;		//pointing to itself since only 1 node
	return temp;
}
node* addAtBeginning(node* tail, int data)
{
	node* head = tail->next;
	node* temp = new node;		//simply use tail->next instead of creating head
	temp->data = data;
	temp->next = head;
	tail->next = temp;		//pointing to new head
	return tail;
}
node* addAtEnd(node* tail, int data)
{
	node* temp = new node;
	node* head = tail->next;	
	temp->data = data;
	tail->next = temp;		//pointing 2nd last node to new node
	temp->next = head;		//pointing new to head
	return temp;
}
node* addAtPos(node* tail, int data,int pos)
{
	if (pos == 1)
	{
		tail = addAtBeginning(tail, data);
		return tail;
	}
	int count = 1;
	node* after = tail->next;
	node* before = NULL;
	node* posNode = new node;
	while (count < pos)
	{
		before = after;
		after = after->next;
		count++;
	}
	if (before == tail)
	{
		tail = addAtEnd(tail, data);
		return tail;
	}
	before->next = posNode;
	posNode->data = data;
	posNode->next = after;
	return tail;
}
node* deleteAtBeginning(node* tail)
{
	node* head = tail->next;
	tail->next = head->next;
	//head->next = NULL;
	delete head;
	head = NULL;
	return tail;
}
node* deleteAtEnd(node* tail)
{
	node* head = tail->next;
	node* temp = head;
	while (temp->next != tail)	//traversing to 2nd last node
	{
		temp = temp->next;
	}
	temp->next = head;	//pointing 2nd last node to head
	delete tail;	//deleting last node
	tail = NULL;
	return temp;
}
node* deleteAtPos(node* tail, int pos)
{
	if (pos == 1)
	{
		tail = deleteAtBeginning(tail);
		return tail;
	}
	int count = 1;
	node* posNode = tail->next;
	node* before = NULL;
	node* temp = new node;
	while (count < pos)
	{
		before = posNode;
		posNode = posNode->next;
		count++;
	}
	before->next = posNode->next;
	if (posNode == tail)
	{
		tail = before;
	}
	delete posNode;
	posNode = NULL;
	return tail;
}
int main()
{
	node* tail = new node;
	tail = addtoEmpty(10);
	tail = addAtBeginning(tail, 20);
	tail = addAtBeginning(tail, 40);
	tail = addAtEnd(tail, 50);
	tail = addAtPos(tail, 60, 3);
	//tail = deleteAtBeginning(tail);
	//tail = deleteAtEnd(tail);
	tail = deleteAtPos(tail, 1);
	printList(tail);
}