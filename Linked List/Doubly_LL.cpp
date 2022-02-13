#include<iostream>

using namespace std;

struct node
{
	node* prev;
	int data;
	node* next;
};

void printList(node* head)
{
	while (head != NULL)
	{
		cout << head->data << endl;
		head = head->next;
	}
}
void printReverseList(node* head)
{
	while (head->next != NULL)
		head = head->next;
	while (head != NULL)
	{
		cout << head->data << endl;
		head = head->prev;
	}
}
void checkPalindrome(node* head)
{
	node* start = head;
	node* end = head;
	while (end->next != NULL)
	{
		end = end->next;
	}
	while (start != NULL && end != NULL)
	{
		if (start->data != end->data)
		{
			cout << "Not Palindrome" << endl;
			return;
		}
		end = end->prev;
		start = start->next;
	}
	cout << "Palindrome" << endl;
}
node* addToList(int data)
{
	node* temp = new node;
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	return temp;
}
node* addAtBeginning(node* head, int data)
{
	if (head == NULL)
	{
		head = addToList(data);
		return head;
	}
	node* temp = new node;
	temp->prev = NULL;
	temp->data = data;
	temp->next = head;
	head->prev = temp;		//linking prev of old head to new head
	head = temp;
	return head;
}
node* addAtEnd(node* head, int data)
{
	if (head == NULL)
	{
		head = addToList(data);
		return head;
	}
	node* temp = new node;
	node* temp2 = NULL;
	temp2 = head;
	while (temp2->next != NULL)		//traversing till final node
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;				//linking final with new node
	temp->prev = temp2;				//linking previous of new with final
	temp->data = data;
	temp->next = NULL;
	return head;
}
node* addAtPos(node* head, int data, int pos)
{
	if (pos == 1)
	{
		head = addAtBeginning(head, data);
		return head;
	}
	int count = 1;
	node* temp = new node;
	node* before = head;
	node* after = head;
	while (count < pos)
	{
		before = after;
		after = after->next;
		count++;
	}
	before->next = temp;
	temp->prev = before;
	temp->data = data;		
	temp->next = after;
	after->prev = temp;
	return head;
}
node* deleteAtBeginning(node* head)
{
	node* temp = head;
	head = head->next;		//or instead of creating temp pointer simply delete(head->prev)
	head->prev = NULL;
	delete temp;
	temp = NULL;
	return head;
}
node* deleteAtEnd(node* head)
{
	node* temp = head;
	node* temp2 = NULL;
	while (temp->next != NULL)
	{
		//temp2 = temp;
		temp = temp->next;
	}
	temp2 = temp->prev;		//pointing temp2 to the 2nd last node
	temp2->next = NULL;
	delete temp;
	temp = NULL;
	return head;
}
node* deleteAtPos(node* head, int pos)
{
	int count = 1;
	node* before = head;
	node* posNode = head;
	while (count < pos - 1)
	{
		before = before->next;	//node at pos - 1
		count++;
	}
	posNode = before->next;	//node at pos
	before->next = posNode->next;		//node at pos - 1 to pos + 1
	if (posNode->next != NULL)
	{
		posNode->next->prev = before;		//node at pos + 1 to previous
	}
	else
	{
		before->next = NULL;
	}
	delete posNode;	//deleting pos node
	posNode = NULL;
	return head;
}
int main()
{
	node* head = new node;
	head = addToList(10);		//creates the list
	head = addAtBeginning(head, 20);
	head = addAtBeginning(head, 40);
	head = addAtEnd(head, 50);
	head = addAtPos(head, 30, 3);
	//head = deleteAtBeginning(head);
	//head = deleteAtEnd(head);
	//head = deleteAtPos(head,3);
	//printList(head);
	printReverseList(head);
	checkPalindrome(head);
	node* head2 = NULL;
	head2 = addToList(1);
	head2 = addAtEnd(head2, 2);
	head2 = addAtEnd(head2, 1);
	checkPalindrome(head2);
}