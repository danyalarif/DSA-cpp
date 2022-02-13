#include<iostream>
#include<string>

using namespace std;

//global variables
char* myStack;
int stackSize;
int top = -1;
void push(char ch)
{
	top++;
	myStack[top] = ch;
}
bool stackEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}
void pop()
{
	top--;
}
bool isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}
char getTop()
{
	return myStack[top];
}
string reverse(string exp)
{
	string temp = "";
	for (int i = 0; i < exp.length(); i++)
	{
		push(exp[i]);
	}
	do
	{
		temp += getTop();
		pop();
	} while (!(stackEmpty()));
	return temp;
}
bool checkPalindrome(string exp)
{
	for (int i = 0; i < exp.length(); i++)
	{
		push(exp[i]);
	}
	int i = 0;
	do
	{
		if (exp[i] != getTop())
			return false;
		pop();
		i++;
	} while (!(stackEmpty()));
	return true;
}
int main()
{
	string exp;
	cout << "Enter an expression: ";
	getline(cin, exp);
	myStack = new char[exp.length()];
	cout << checkPalindrome(exp) << endl;
}
