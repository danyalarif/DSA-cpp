#include<iostream>
#include<string>

using namespace std;

//global variables
int* myStack;
int stackSize;
int top = -1;
int stringToInt(string exp)
{
	int digit, res = 0;
	for (int i = 0; i < exp.length(); i++)
	{
		digit = (int)exp[i] - 48;
		res = (res * 10) + digit;
	}
	return res;
}
void push(int x)
{
	top++;
	myStack[top] = x;
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
int getTop()
{
	return myStack[top];
}
int solvePostFix(string exp)
{
	int a, b, i = 0;
	char temp;
	string tempString;
	while (i < exp.length())
	{
		temp = exp[i];
		if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
		{
			b = getTop();
			pop();
			a = getTop();
			pop();
			switch (temp)
			{
			case '+':
			{
				push(a + b);
				break;
			}
			case '-':
			{
				push(a - b);
				break;
			}
			case '*':
			{
				push(a * b);
				break;
			}
			case '/':
			{
				push(a / b);
				break;
			}
			}
		}
		else if (temp >= '0' && temp <= '9')
		{
			do
			{
				temp = exp[i];
				if (temp >= '0' && temp <= '9')
					tempString += temp;
				i++;
			} while ((i != exp.length()) && (temp >= '0' && temp <= '9'));
			push(stringToInt(tempString));
			i--;
			tempString = "";
			continue;
		}
		else if (temp == ' ')
		{
			i++;
			continue;
		}
		else
		{
			cout << "Invalid Expression" << endl;
			return 0;
		}
		i++;
	}
	return getTop();
}

int main()
{
	string exp;
	cout << "Enter an expression: ";
	getline(cin, exp);
	myStack = new int[exp.length()];
	stackSize = exp.length();
	cout << solvePostFix(exp) << endl;
}
