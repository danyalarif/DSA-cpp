#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* front = NULL;
node* rear = NULL;
void enqueue();
void dequeue();
void display();
void menu();
int main()
{
	int choice;
	do
	{
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			enqueue();
		}
		else if (choice == 2)
		{
			dequeue();
		}
		else if (choice == 3)
		{
			display();
		}
		else if (choice == 4)
		{
			break;
			//exit(0);
		}
		else
		{
			cout << "Invalid input!" << endl;
		}
	} while (choice != 4);
}
void enqueue()
{
	node* temp = new node;
	int x;
	cout << "Enter value: ";
	cin >> x;
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL)
	{
		rear = front = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}
void dequeue()
{
	if (front == NULL && rear == NULL)
	{
		cout << "Queue is EMPTY!" << endl;
		return;
	}
	int tempData = front->data;
	node* temp = front;
	if (front == rear)
	{
		front = rear = NULL;
		delete temp;
		temp = NULL;
	}
	else
	{
		front = front->next;
		delete temp;
		temp = NULL;
	}
	cout << tempData << " is deleted!" << endl;
}
void display()
{
	if (front == NULL && rear == NULL)
	{
		cout << "Queue is EMPTY!" << endl;
		return;
	}
	node* temp = NULL;
	temp = front;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void menu()
{
	cout << "\n\nQUEUE FUNCTIONS WITH LL" << endl;
	cout << "1. ENQUEUE" << endl;
	cout << "2. DEQUEU" << endl;
	cout << "3. DISPLAY" << endl;
	cout << "4. EXIT\n" << endl;
}