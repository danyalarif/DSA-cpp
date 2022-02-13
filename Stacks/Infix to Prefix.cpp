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
int getPrecedence(char op)
{
	if (op == '(' || op == '{' || op == '[')
		return 0;
	else if (op == '^')
		return 3;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
}
string reverseExpression(string exp)
{
	string rev;
	for (int i = exp.length() - 1; i >= 0; i--)
	{
		if (exp[i] == '(')
			rev += ')';
		else if (exp[i] == ')')
			rev += '(';
		else
			rev += exp[i];
	}
	return rev;
}
string infixToPrefix(string exp)
{
	exp = reverseExpression(exp);
	string res;
	char temp;
	int i = 0;
	while (i < exp.length())
	{
		if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
		{
			res += exp[i];
		}
		else if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			do
			{
				temp = getTop();
				if (temp != '(')
					res += temp;
				pop();
			} while (temp != '(');
		}
		else if (exp[i] == '}')
		{
			do
			{
				temp = getTop();
				res += temp;
				/*if (temp == ')' || temp == ']')
					return false;*/
				pop();
			} while (temp != '{');
		}
		else if (exp[i] == ']')
		{
			do
			{
				temp = getTop();
				res += temp;
				/*if (temp == '}' || temp == ')')
					return false;*/
				pop();
			} while (temp != '[');
		}
		else if (isEmpty())
		{
			push(exp[i]);
		}
		else if ((!isEmpty()) && (getPrecedence(exp[i]) > getPrecedence(getTop())))
		{
			push(exp[i]);
		}
		else if ((!isEmpty()) && (getPrecedence(exp[i]) < getPrecedence(getTop())))
		{
			res += getTop();
			pop();
			continue;
		}
		else if ((!isEmpty()) && (getPrecedence(exp[i]) == getPrecedence(getTop())))
		{
			if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
			{
				push(exp[i]);
			}
			else if (exp[i] == '^')
			{
				res += getTop();
				pop();
				continue;
			}
		}
		i++;
	}
	if (!(isEmpty()))
	{
		do
		{
			temp = getTop();
			res += temp;
			/*if (temp == '(' || temp == '{' || temp == '[')
				return false;*/
			pop();
		} while ((!isEmpty()));
	}
	res = reverseExpression(res);
	return res;
}
int main()
{
	string exp;
	cout << "Enter an expression: ";
	getline(cin, exp);
	myStack = new char[exp.length()];
	stackSize = exp.length();
	cout << infixToPrefix(exp) << endl;
}
