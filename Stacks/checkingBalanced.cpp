#include<iostream>
#include<string>

using namespace std;

//global variables
char *myStack;
int stackSize;
int top = -1;
void push(char ch)
{
	top++;
	myStack[top] = ch;
}
void pop()
{
	top--;
}
char getTop()
{
	return myStack[top];
}
bool checkBalanced(string exp)
{
	char temp;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '=' || exp[i] == '*' || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
		{
			push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			do
			{
				temp = getTop();
				if (temp == '}' || temp == ']')
					return false;
				pop();
			} while (temp != '(');
		}
		else if (exp[i] == '}')
		{
			do
			{
				temp = getTop();
				if (temp == ')' || temp == ']')
					return false;
				pop();
			} while (temp != '{');
		}
		else if (exp[i] == ']')
		{
			do
			{
				temp = getTop();
				if (temp == '}' || temp == ')')
					return false;
				pop();
			} while (temp != '[');
		}
	}
	while (top != -1)
	{
		temp = getTop();
		if (temp == '(' || temp == '{' || temp == '[')
			return false;
		pop();
	}
	return true;
}
int main()
{
	string exp;
	cout << "Enter an expression: ";
	getline(cin, exp);
	myStack = new char[exp.length()];
	stackSize = exp.length();
	if (checkBalanced(exp))
		cout << "True" << endl;
}
