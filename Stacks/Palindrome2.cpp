#include<iostream>
#include<string>

using namespace std;

struct node
{
	char data;
	node* next;
};

node* top = NULL;

void push(char x);
void pop();
char getTop();
void menu();
bool checkPalindrome(string exp);
int main()
{
	string exp;
	cout << "Enter an expression: ";
	getline(cin, exp);
	cout << checkPalindrome(exp) << endl;
}
bool checkPalindrome(string exp)
{
	for (int i = 0; i < exp.length(); i++)
	{
		push(exp[i]);
	}
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] != getTop())
		{
			return false;
		}
		pop();
	}
	return true;
}
void push(char x)
{
	node* temp = new node;
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
}
char getTop()
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