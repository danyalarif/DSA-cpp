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
string infixToPostfix(string exp)
{
	string res;
	char temp;
	int i = 0;
	while (i < exp.length())
	{
		if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
		{
			res += exp[i];
		}
		else if (exp[i] >= '0' && exp[i] <= '9')
		{
			char temp;
			do
			{
				temp = exp[i];
				if (temp >= '0' && temp <= '9')
					res += temp;
				i++;
			} while ((i != exp.length()) && (temp >= '0' && temp <= '9'));
			if (i == exp.length() && exp[i - 1] >= '0' && exp[i] <= '9')
				break;
			res += " ";
			i--;
			continue;
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
				res += getTop();
				pop();
				push(exp[i]);
			}
			else if (exp[i] == '^')
			{
				push(exp[i]);
			}
		}
		i++;
	}
	if (isEmpty())
		return res;
	do
	{
		temp = getTop();
		res += temp;
		/*if (temp == '(' || temp == '{' || temp == '[')
			return false;*/
		pop();
	} while ((!isEmpty()));
	return res;
}

int main()
{
	string exp;
	cout << "Enter an expression: ";
	getline(cin, exp);
	myStack = new char[exp.length()];
	stackSize = exp.length();
	cout << infixToPostfix(exp) << endl;
}
