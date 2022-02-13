#include<iostream>
#include<stack>

using namespace std;

//global variables
int myStack[3];
int stackSize = sizeof(myStack) / sizeof(myStack[0]);
int top = -1;
bool isfull();
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
void pop()
{
	if (top == -1)
	{
		cout << "Stack is Empty!" << endl;
		return;
	}
	cout << myStack[top] << " is popped out!" << endl;
	myStack[top] == 0;
	top--;
}
void push()
{
	if (isfull())	//if already an element exist on the last index
	{
		cout << "Stack Overflow!" << endl;
		return;
	}
	int x;
	cout << "Enter the value to be pushed: ";
	cin >> x;
	top++;
	myStack[top] = x;
}
int getTop()
{
	if (top == -1)
	{
		cout << "Stack is Empty!" << endl;
	}
	else
		return myStack[top];
}
bool isfull()
{
	if (top == stackSize - 1)
		return true;
	else
		return false;
}
void menu()
{
	cout << "\n\nSTACK FUNCTIONS" << endl;
	cout << "1. PUSH" << endl;
	cout << "2. POP" << endl;
	cout << "3. TOP" << endl;
	cout << "4. EXIT\n" << endl;
}
