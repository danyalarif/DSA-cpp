#include<iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};

node* top = NULL;

void push();
void pop();
int getTop();
void menu();
int main()
{
	int choice, topValue;
	do
	{
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			push();
		}
		else if (choice == 2)
		{
			pop();
		}
		else if (choice == 3)
		{
			cout << getTop() << endl;
		}
		else if (choice == 4)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid input!" << endl;
		}
	} while (choice != 4);
}

void push()
{
	node* temp = new node;
	int x;
	cout << "Enter value to be pushed: ";
	cin >> x;
	if (top == NULL)	//if stack is empty
	{
		temp->next = NULL;
		temp->data = x;
		top = temp;
		return;
	}
	temp->next = top;
	temp->data = x;
	top = temp;
}
void pop()
{
	if (top == NULL)
	{
		cout << "Stack is Empty!" << endl;
		return;
	}
	node* temp = top;
	top = top->next;
	delete temp;
	temp = NULL;
	cout << "Value popped off successfully!" << endl;
}
int getTop()
{
	if (top == NULL)
	{
		cout << "Stack is Empty!" << endl;
	}
	else
	{
		return top->data;
	}
}
void menu()
{
	cout << "\n\nSTACK FUNCTIONS WITH LL" << endl;
	cout << "1. PUSH" << endl;
	cout << "2. POP" << endl;
	cout << "3. TOP" << endl;
	cout << "4. EXIT\n" << endl;
}