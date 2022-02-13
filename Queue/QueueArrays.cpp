#include<iostream>

using namespace std;

int queue[5];
int queueSize = sizeof(queue) / sizeof(queue[0]);
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void qdisplay();
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
			qdisplay();
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
	if (rear == queueSize - 1)
	{
		cout << "Queue Overflow!\n" << endl;
		return;
	}
	int x;
	cout << "Enter a value: ";
	cin >> x;
	if (front == -1)
		front++;
	rear++;
	queue[rear] = x;
}
void dequeue()
{
	if (front == -1 || front > rear)
	{
		cout << "Queue Underflow!\n" << endl;
		return;
	}
	cout << queue[front] << " is deleted!" << endl;
	front++;
}
void qdisplay()
{
	if (front == -1 || front > rear)
	{
		cout << "Queue is Empty!\n" << endl;
		return;
	}
	for (int i = front; i <= rear; i++)
	{
		cout << queue[i] <<" ";
	}
	cout << endl;
}
void menu()
{
	cout << "\n\nQUEUE FUNCTIONS WITH ARRAY" << endl;
	cout << "1. ENQUEUE" << endl;
	cout << "2. DEQUEU" << endl;
	cout << "3. DISPLAY" << endl;
	cout << "4. EXIT\n" << endl;
}